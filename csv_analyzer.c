#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // Maximum length for a line in the CSV file
#define NUM_EVENTS 8  // Number of different events to calculate averages for

// Struct to hold data for each athlete
typedef struct {
    char name[50];       // Athlete's name
    double free_50;      // 50m freestyle time in seconds
    double best_50;      // 50m best stroke time in seconds
    double free_100;     // 100m freestyle time in seconds
    double best_100;     // 100m best stroke time in seconds
    double max_sets;     // Max sets in CrossFit event
    double max_pushups;  // Max pushups in 60 seconds
    double run_botke;    // Run "Botke" time
    double test_12;      // Test 12 result
} Athlete;

// Function to convert a time string (MM:SS:MS) to total seconds
double parse_time_to_seconds(const char *time_str) {
    int minutes = 0, seconds = 0, milliseconds = 0;
    sscanf(time_str, "%d:%d:%d", &minutes, &seconds, &milliseconds);  // Parse minutes, seconds, and milliseconds from the string
    return minutes * 60 + seconds + milliseconds / 100.0;  // Return the total time in seconds
}

// Function to convert seconds to a formatted time string (MM:SS:MS)
void format_seconds_to_time(double total_seconds, char *buffer) {
    int minutes = (int) total_seconds / 60;
    int seconds = (int) total_seconds % 60;
    int milliseconds = (int) ((total_seconds - minutes * 60 - seconds) * 100);
    sprintf(buffer, "%02d:%02d:%02d", minutes, seconds, milliseconds);
}

// Function to read the CSV file and store data in the athletes array
void read_csv(const char *filename, Athlete *athletes, int *num_athletes) {
    FILE *file = fopen(filename, "r");  // Open the CSV file for reading
    if (!file) {  // Check if the file was opened successfully
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];  // Buffer to store each line of the CSV file
    int count = 0;  // Counter for the number of athletes

    fgets(line, sizeof(line), file);  // Skip the header line

    // Read each line of the CSV file and parse the data
    while (fgets(line, sizeof(line), file)) {
        char free_50_str[20], best_50_str[20], free_100_str[20], best_100_str[20], run_botke_str[20];
        sscanf(line, "%49[^,],%19[^,],%19[^,],%19[^,],%19[^,],%lf,%lf,%19[^,],%lf",
               athletes[count].name,
               free_50_str,
               best_50_str,
               free_100_str,
               best_100_str,
               &athletes[count].max_sets,
               &athletes[count].max_pushups,
               run_botke_str,
               &athletes[count].test_12);

       // Debugging statements to check parsed values
        printf("Parsed %s: 50 best stroke=%s\n", athletes[count].name, best_50_str);

        // Convert time strings to seconds
        athletes[count].free_50 = (strlen(free_50_str) > 0) ? parse_time_to_seconds(free_50_str) : 0;
        athletes[count].best_50 = (strlen(best_50_str) > 0) ? parse_time_to_seconds(best_50_str) : 0;

        // Convert 100m times if present
        athletes[count].free_100 = (strlen(free_100_str) > 0) ? parse_time_to_seconds(free_100_str) : 0;
        athletes[count].best_100 = (strlen(best_100_str) > 0) ? parse_time_to_seconds(best_100_str) : 0;

        // Convert run "Botke" time if present
        athletes[count].run_botke = (strlen(run_botke_str) > 0) ? atof(run_botke_str) : 0;

        count++;  // Increment the number of athletes
    }

    *num_athletes = count;  // Store the total number of athletes
    fclose(file);  // Close the CSV file
}

// Function to calculate the averages for each event
void calculate_averages(Athlete *athletes, int num_athletes, double *averages, int *valid_counts) {
    memset(averages, 0, NUM_EVENTS * sizeof(double));  // Initialize the averages array to zero
    memset(valid_counts, 0, NUM_EVENTS * sizeof(int)); // Initialize the valid counts array to zero

    // Iterate over each athlete and sum up their event results
    for (int i = 0; i < num_athletes; i++) {
        if (athletes[i].free_50 > 0) { averages[0] += athletes[i].free_50; valid_counts[0]++; }
        if (athletes[i].best_50 > 0) { averages[1] += athletes[i].best_50; valid_counts[1]++; }
        if (athletes[i].free_100 > 0) { averages[2] += athletes[i].free_100; valid_counts[2]++; }
        if (athletes[i].best_100 > 0) { averages[3] += athletes[i].best_100; valid_counts[3]++; }
        if (athletes[i].max_sets > 0) { averages[4] += athletes[i].max_sets; valid_counts[4]++; }
        if (athletes[i].max_pushups > 0) { averages[5] += athletes[i].max_pushups; valid_counts[5]++; }
        if (athletes[i].run_botke > 0) { averages[6] += athletes[i].run_botke; valid_counts[6]++; }
        if (athletes[i].test_12 > 0) { averages[7] += athletes[i].test_12; valid_counts[7]++; }
    }

    // Calculate averages
    for (int i = 0; i < NUM_EVENTS; i++) {
        if (valid_counts[i] > 0) {
            averages[i] /= valid_counts[i];
        }
    }

        // Debugging statements to check calculated averages and counts
    for (int i = 0; i < NUM_EVENTS; i++) {
        printf("Event %d: average = %f, valid count = %d\n", i, averages[i], valid_counts[i]);
    }
}

// Function to write the averages to a new CSV file
void write_csv(const char *filename, double *averages, int *valid_counts) {
    FILE *file = fopen(filename, "w");  // Open the CSV file for writing
    if (!file) {  // Check if the file was opened successfully
        perror("Could not open file");
        return;
    }

    char time_buffer[20];  // Buffer to store formatted time strings

    // Write the header and averages for each event to the CSV file
    fprintf(file, "Event,Average\n");

    if (valid_counts[0] > 0) {
        format_seconds_to_time(averages[0], time_buffer);
        fprintf(file, "50 Free,%s\n", time_buffer);
    } else {
        fprintf(file, "50 Free,N/A\n");
    }

    if (valid_counts[1] > 0) {
        format_seconds_to_time(averages[1], time_buffer);
        fprintf(file, "50 Best Stroke,%s\n", time_buffer);
    } else {
        fprintf(file, "50 Best Stroke,N/A\n");
    }

    if (valid_counts[2] > 0) {
        format_seconds_to_time(averages[2], time_buffer);
        fprintf(file, "100 Free,%s\n", time_buffer);
    } else {
        fprintf(file, "100 Free,N/A\n");
    }

    if (valid_counts[3] > 0) {
        format_seconds_to_time(averages[3], time_buffer);
        fprintf(file, "100 Best Stroke,%s\n", time_buffer);
    } else {
        fprintf(file, "100 Best Stroke,N/A\n");
    }

    fprintf(file, "Crossfit Max Sets,%.2f\n", valid_counts[4] > 0 ? averages[4] : 0);
    fprintf(file, "Max Pushups in 60 Sec,%.2f\n", valid_counts[5] > 0 ? averages[5] : 0);
    fprintf(file, "Run \"Botke\",%.2f\n", valid_counts[6] > 0 ? averages[6] : 0);
    fprintf(file, "Test 12,%.2f\n", valid_counts[7] > 0 ? averages[7] : 0);

    fclose(file);  // Close the CSV file
}

int main() {
    const char *input_filename = "data.csv";       // Input CSV file
    const char *output_filename = "averages_output.csv";  // Output CSV file

    Athlete athletes[100];  // Array to hold athlete data
    int num_athletes = 0;   // Number of athletes
    double averages[NUM_EVENTS];  // Array to hold averages for each event
    int valid_counts[NUM_EVENTS]; // Array to hold the count of valid entries for each event

    read_csv(input_filename, athletes, &num_athletes);  // Read the CSV file
    calculate_averages(athletes, num_athletes, averages, valid_counts);  // Calculate the averages
    write_csv(output_filename, averages, valid_counts);  // Write the averages to a new CSV file

    return 0;  // Exit the program
}
