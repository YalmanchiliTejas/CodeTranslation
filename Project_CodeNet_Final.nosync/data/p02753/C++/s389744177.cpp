#include<iostream>
#include<string>
using namespace std;

int main(){
    string station;
    cin >> station;
    if(station.substr(0,1) == station.substr(1,1) &&station.substr(1,1) == station.substr(2,1) && station.substr(0,1) == station.substr(2,1)){
        cout << "No";
    }else{
        cout << "Yes";
    }

    return 0;
}
