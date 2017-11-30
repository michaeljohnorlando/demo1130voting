
//Liang Orlando
#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include <time.h>       /* time */

using namespace std;



void create_db_and_seed(){
    //check if the file allready exists
    ifstream infile("voter_db.txt");
    if(infile.good()){
        return;
    }
    
    //create and seed the DB
    ofstream voter_db;
    voter_db.open("voter_db.txt");
    for(int x=0;x<11;x++){
        voter_db<<rand()%9000 +1<<"\n";
    }
    voter_db.close();
}
int main_menu_voter_id(){
    int voter_id;
    cout<<"    Electrinic Vote \n"
        <<"Enter voter ID: "; 
    cin>>voter_id;
    return voter_id;
}
bool serch_db_id(int voter_id){
    string line;
    fstream search_db ("voter_db.txt");
    if(search_db.is_open()){
        while(getline(search_db,line)){
            if(stoi(line)==voter_id){
                search_db.close();
                return true;
            }
        }
    search_db.close();
    return false;
    }
    
}

main(){
    srand(time(0));
    
    create_db_and_seed();
    
    
    
}
/*
bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
*/
