#include<iostream>
using namespace std;
int main(){
    char c;
    string res;
    cin >> c;
    if(c=='a'||c=='e'||c=='i'||c=='o'|c=='u') res = "vowel";
    else res = "consonant";
    cout << res << endl; 
}