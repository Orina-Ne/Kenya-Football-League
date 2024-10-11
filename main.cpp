#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Fixture{
    string home_team;
    string away_team;
    string stadium;
    string hometown;
    int leg;
    int weekend;
    string day;
};

string team_names[10];
string home_towns[10];
string stadiums[10];
const string file_name = "team.csv";
int count = 0;
vector<Fixture> fixtures;

void read_csv(const string file_name){
    ifstream csv_file(file_name);
    string line;

    while (getline(csv_file,line) && count < 10){
        stringstream ss(line);
        getline(ss, team_names[count], ',');
        getline(ss, home_towns[count], ',');
        getline(ss, stadiums[count]);
        count++;
    }
    csv_file.close();
}

void generate_fixtures(){
    int weekend = 1;
    int match_count = 0;

    //A loop in a loop is used to pass through each team
    for(int i = 0; i < count; i++){
        //join each team with another
        for(int j = i + 1; j < count; j++){
            //make sure that teams from different home towns play first
            if(home_towns[i] != home_towns[j]){
                fixtures.push_back({team_names[i], team_names[j], stadiums[i], home_towns[i], 1, weekend, "Saturday"});
                match_count++;
                //Second leg fixture
                fixtures.push_back({team_names[j], team_names[i], stadiums[j], home_towns[j], 2, weekend, "Sunday"});
                match_count++;

                if (match_count == 2){
                    weekend++;
                    match_count = 0;
                }
            }
        }
    }

    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(home_towns[i] == home_towns[j]){
                fixtures.push_back({team_names[i], team_names[j], stadiums[i], home_towns[i], 1, weekend, "Saturday"});
                match_count++;

                fixtures.push_back({team_names[j], team_names[i], stadiums[j], home_towns[j], 2, weekend, "Sunday"});
                match_count++;

                if(match_count == 2){
                    weekend++;
                    match_count = 0;
                }
            }
        }
    }
}

void write_fixtures(){
    ofstream matches("fixtures.csv");
    matches<<"Weekend, Home Team, Away Team, Stadium, Day, Leg"<<endl;

    for(int k = 0; k < fixtures.size(); k++){
        matches<<fixtures[k].weekend<<",";
        matches<<fixtures[k].home_team<<",";
        matches<<fixtures[k].away_team<<",";
        matches<<fixtures[k].stadium<<",";
        matches<<fixtures[k].day<<",";
        matches<<fixtures[k].leg<<endl;
    }

    matches.close();
}

void write_fixtures(){
        ofstream matches("fixtures.csv");
        matches<<"Weekend, Home Team, Away Team, Stadium, Leg"<<endl;

        for(int k = 0; k < fixtures.size(); k++){
            matches<<fixtures[k].weekend<<",";
            matches<<fixtures[k].home_team<<",";
            matches<<fixtures[k].away_team<<",";
            matches<<fixtures[k].stadium<<",";
            matches<<fixtures[k].leg<<endl;
        }

        matches.close();
    }

int main() {
    read_csv(file_name);
    generate_fixtures();
    write_fixtures();

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