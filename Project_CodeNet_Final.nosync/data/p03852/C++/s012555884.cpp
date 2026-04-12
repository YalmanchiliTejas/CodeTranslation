#include <iostream>

using namespace std;

int main(){
    char c;
    cin >> c;

    string tmp = "aeiou";

    if(tmp.find(c) == string::npos) cout << "consonant" << endl;
    else cout << "vowel" << endl;
}
