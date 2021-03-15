//g++ -g -Wall -std=c++11 tweet_parse.cpp -o tweet_parse

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

string reversed(vector<string> name){
    string rvrs;

    rvrs.append(string(name.back()));
    rvrs.append(", ");

    vector<string>::iterator it;
    for(it = name.begin(); it != name.end() - 1; it++){
        rvrs.append(*it);
        rvrs.append(" ");
    }

    return(rvrs);
}


int main(int argc, char** argv){
    char* filename = argv[1];  //filename is the first thing given after you command to run the code 

	ifstream file(filename); //open file
    string line;

    while(getline(file, line)){
        istringstream ss(line);
        vector<string> name;
        string value;

        while(ss >> value) {
            name.push_back(value);
        }
        string reversed_name = reversed(name);

        cout << reversed_name << endl;
        
    }
}
