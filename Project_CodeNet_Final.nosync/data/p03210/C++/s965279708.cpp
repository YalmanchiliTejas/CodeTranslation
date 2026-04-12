#include <cmath>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

//-----------------------------------------
string happy_753(int X){

    string str;
    if(X==7 || X==5|| X==3){
        str = "YES"; 
    }else{
        str = "NO";
    };

    return str;
}

int main() {
    // I/O format
    int X; cin >> X;
    string out;

    out = happy_753(X);
    cout << out << endl;
}