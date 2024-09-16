#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string team_names[10];
string home_towns[10];
string stadiums[10];
const string file_name = "team.csv";
int count = 0;

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
int main() {
    read_csv(file_name);

    // for(int i = 0; i < count; i++){
    //     cout<<team_names[i]<<endl;
    // }

    cout<<team_names[2]<<endl;
    cout<<home_towns[2]<<endl;
    cout<<stadiums[2]<<endl;
    return 0;
}