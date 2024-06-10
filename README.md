<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CSV Analyzer</title>
</head>
<body>

  <h1>CSV Analyzer</h1>

  <p>CSV Analyzer is a C program designed to read and analyze CSV files containing athlete performance data. The program calculates the average performance metrics for various events and outputs the results to a new CSV file.</p>
  <p><strong>This program is being used by Coach Gabi Silverman and David Baron from Makabi Marom Ramat Gan Swimming Club. David Baron is training Jonathan Itzhaki, the Israeli champion in 100 breaststroke, with this program.</strong></p>
  <p><strong>Please note that this program is not final and is subject to change and implementation of new features.</strong></p>

  <h2>Features</h2>
  <ul>
    <li>Reads CSV files with athlete performance data.</li>
    <li>Calculates average times for:
      <ul>
        <li>50m Freestyle</li>
        <li>50m Best Stroke</li>
        <li>100m Freestyle</li>
        <li>100m Best Stroke</li>
      </ul>
    </li>
    <li>Calculates average metrics for:
      <ul>
        <li>Crossfit Max Sets</li>
        <li>Max Pushups in 60 Seconds</li>
        <li>Run "Botke"</li>
        <li>Test 12</li>
      </ul>
    </li>
    <li>Outputs the calculated averages to a new CSV file.</li>
  </ul>

  <h2>Prerequisites</h2>
  <ul>
    <li>GCC (GNU Compiler Collection)</li>
  </ul>

  <h2>Installation</h2>
  <ol>
    <li><strong>Clone the repository:</strong>
      <pre><code>git clone https://github.com/YourUsername/csv_analyzer.git
cd csv_analyzer</code></pre>
    </li>
    <li><strong>Compile and run the program:</strong>
      <pre><code>gcc -o csv_analyzer csv_analyzer.c
./csv_analyzer</code></pre>
    </li>
  </ol>

  <h2>Usage</h2>
  <ol>
    <li><strong>Prepare your CSV file:</strong>
      <ul>
        <li>Ensure your CSV file follows the format expected by the program.</li>
        <li>Modify the data as you need.</li>
      </ul>
    </li>
    <li><strong>Run the program:</strong>
      <pre><code>./csv_analyzer</code></pre>
    </li>
    <li><strong>Check the output:</strong>
      <ul>
        <li>The program will create a new CSV file named <code>output.csv</code> with the calculated averages.</li>
      </ul>
    </li>
  </ol>

  <h2>Support</h2>
  <p>For support or inquiries, please contact <a href="mailto:markshperkin1@gmail.com">Mark Shperkin</a>.</p>

</body>
</html>
