# Football League Fixture Generator

**This project generates football fixtures for a 10-team league, following specific rules. Each team plays every other team twice (home and away), and teams from the same hometown only face each other after playing teams from different hometowns. The fixtures are saved in a CSV file and displayed in the console.**

##Structure

**The main files in the project include:**
   **team.csv: Contains the list of teams, their hometowns and their stadiums.**
   **fixtures.csv: Outputs the generated fixtures.**
   **main.cpp: contains the souce code that reads the team data, generates the fixtures and writes the results to a CSV file.**

##Libraries Used

**iostream: for reading and displaying data in the console**
**fstream: reading team data from a CSV file and writing the generated fixtures to a CSV file.**
**sstream: used for parsing CSV data into individual components(Team name, Hometown, Stadium)**
**vector: used to store generated fixtures in an array like structure**

##How to Run

**1: Prepare a team.csv file containing the team details in the format of Team name, Hometown and Stadium**
**2: Compile the c++ program**
**3: Run the compiled program**
**4: The generated fixtures will be displayed on the console and also be written in the csv file**