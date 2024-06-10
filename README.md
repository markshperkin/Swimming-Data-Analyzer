# CSV Analyzer

CSV Analyzer is a C program designed to read and analyze CSV files containing athlete performance data. The program calculates the average performance metrics for various events and outputs the results to a new CSV file.
**This program is being used by Coach Gabi Silverman and David Baron from Makabi Marom Ramat Gan Swimming Club. David Baron is training Jonathan Itzhaki, the Israeli champion in 100 breaststroke, with this program.**
**Please note that this program is not final and is subject to change and implementation of new features.**


## Features

- Reads CSV files with athlete performance data.
- Calculates average times for:
  - 50m Freestyle
  - 50m Best Stroke
  - 100m Freestyle
  - 100m Best Stroke
- Calculates average metrics for:
  - Crossfit Max Sets
  - Max Pushups in 60 Seconds
  - Run "Botke"
  - Test 12
- Outputs the calculated averages to a new CSV file.

## Prerequisites

- GCC (GNU Compiler Collection)

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/YourUsername/csv_analyzer.git
    cd csv_analyzer
    ```

2. **Compile and run the program:**
    ```sh
    gcc -o csv_analyzer csv_analyzer.c
    ./csv_analyzer
    ```

## Usage

1. **Prepare your CSV file:**
   - Ensure your CSV file follows the format expected by the program.
   - change 

2. **Run the program:**
    ```sh
    ./csv_analyzer
    ```

3. **Check the output:**
   - The program will create a new CSV file named `averages_output.csv` with the calculated averages.

## Example

Here is an example of how to use the program:

1. **Input CSV (`data.csv`):**
    ```csv
    name of athlete,50 free,50 best stroke,100 free,100 best stroke,crosfit max sets in 10 min (3 pushups, 7 squats, 20 abs),max pushups in 60 sec,run "Botke",test 12
    Ana 2009,0:33:00,00:46:00 breast,1:15,1:41:03 breast,12,9.5,3.5,550
    Ariel 2010,0:37:00,00:47:00 fly,1:20:00,2:02:07 breast,12,10,,50
    ...
    ```

2. **Run the program:**
    ```sh
    ./csv_analyzer
    ```

3. **Output CSV (`averages_output.csv`):**
    ```csv
    Event,Average
    50 Free,00:45:12
    50 Best Stroke,00:51:30
    100 Free,01:35:45
    100 Best Stroke,01:48:20
    Crossfit Max Sets,10.50
    Max Pushups in 60 Sec,8.25
    Run "Botke",2.75
    Test 12,450.00
    ```
