#include <iostream>
#include <string>
using namespace std;

int main(){
    string z;
    cin >> z;
    if(z == "a"){cout << "vowel" << endl;}
    else if(z == "i"){cout << "vowel" << endl;}
    else if(z == "u"){cout << "vowel" << endl;}
    else if(z == "e"){cout << "vowel" << endl;}
    else if(z == "o"){cout << "vowel" << endl;}
    else cout << "consonant" << endl;

    return 0;
}