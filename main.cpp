#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//Structure has been used to hold each fixtures details .
struct Fixture{
    string home_team;
    string away_team;
    string stadium;
    string hometown;
    int leg;
    int weekend;
};
// Arrays are used to store the collection of the teams  details
string team_names[10];
string home_towns[10];
string stadiums[10];
//This is the file from CSV that contains data of teams
const string file_name = "team.csv";
int count = 0;
vector<Fixture> fixtures;
//This function reads Data from the CSV file however it does not return it
void read_csv(const string file_name){
    ifstream csv_file(file_name);
    string line;
//read each line of CSV file until 10 teams details are reached
    while (getline(csv_file,line) && count < 10){
        stringstream ss(line);
        getline(ss, team_names[count], ',');
        getline(ss, home_towns[count], ',');
        getline(ss, stadiums[count]);
        count++;
    }
    csv_file.close();
}
//This function is building fixtures for the teams involved .
void generate_fixtures(){
    int weekend = 1;
    int match_count = 0;
//Loop is used to create fixtures for each pair of fixtures
    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(home_towns[i] != home_towns[j]){

                fixtures.push_back({team_names[i], team_names[j], stadiums[i], home_towns[i], 1, weekend});
                match_count++;

                fixtures.push_back({team_names[j], team_names[i], stadiums[j], home_towns[j], 2, weekend});
                match_count++;
//This confirms that during each weekend 2 matches are played
                if (match_count == 2){
                    weekend++;
                    match_count = 0;
                }
            }
        }
    }
//This is the derby iteration structure .
    for(int i = 0; i < count; i++){
            for(int j = i + 1; j < count; j++){
                if(home_towns[i] == home_towns[j]){
                    fixtures.push_back({team_names[i], team_names[j], stadiums[i], home_towns[i], 1, weekend});
                    match_count++;

                    fixtures.push_back({team_names[j], team_names[i], stadiums[j], home_towns[j], 2, weekend});
                    match_count++;

                    if(match_count == 2){
                        weekend++;
                        match_count = 0;
                    }
                }
            }
        }
}

void filter_weekends(int weekend_no){
      for(int i = 0; i <  fixture.size(); i++){
          if(fixtures[i].weekend == weekend_no){
          cout<<fixtures[i].weekend<<endl;
          }else{
          cout<<"Invalid weekend"<<endl;
          }
      }
}
// A function to read the csv file
int main() {
    int weekend_number;
    read_csv(file_name);
    generate_fixtures();
    cout<< "Welcome to ABC Premier league"<<endl;
    cout<< "This program will generate your fixtures "<<endl;
    cout << " User enter match weekend ."<<endl;
    cin>> weekend_number;
    filter_weekends(weekend_number);

    for(int k = 0; k < fixtures.size(); k++){
        cout<<fixtures[k].weekend<<endl;
        cout<<fixtures[k].home_team <<endl;
        cout<<  "vs\n";
        cout <<fixtures[k].away_team<< endl;
        cout<<fixtures[k].stadium<< endl;
        cout<<fixtures[k].leg<<"leg"<< endl;
        cout<<"______________________________________________"<<endl;
    }

    return 0;
}