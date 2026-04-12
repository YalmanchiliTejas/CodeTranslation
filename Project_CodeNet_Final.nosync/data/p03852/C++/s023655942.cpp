#include <iostream>
#include <string>
using namespace std;

int main(){
    string c;
    bool res = false;
    
    cin >> c;
    
    if(c == "a") res = true;
    if(c == "i") res = true;
    if(c == "e") res = true;
    if(c == "o") res = true;
    if(c == "u") res = true;
    
    if(res) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}