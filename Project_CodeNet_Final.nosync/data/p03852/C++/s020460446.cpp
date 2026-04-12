#include<iostream>
#include<string>
using namespace std;

int main(){
    char x;
    cin >> x ;
    
    // if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o') cout << "vowel" << endl;
    // else cout << "consonant" << endl;

    const string a = "aiueo";

    cout << ((a.find(x) != string::npos) ? "vowel" : "consonant") << endl;
    // cout << (a.find(x) == string::npos) << endl;


    
}