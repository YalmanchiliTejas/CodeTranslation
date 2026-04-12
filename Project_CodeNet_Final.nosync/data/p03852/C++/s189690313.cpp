#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {


    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    string c;
    cin >> c;
    if(c == "a" ||
       c == "i" ||
       c == "u" ||
       c == "e" ||
       c == "o"){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}
