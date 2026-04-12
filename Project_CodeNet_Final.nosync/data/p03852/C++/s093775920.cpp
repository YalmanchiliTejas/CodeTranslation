#include<iostream>
#include<string>
using namespace std;

int main(){
    string tmp = "aiueo",c;
    cin >> c;
    if(tmp.find(c) != -1)cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}