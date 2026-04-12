#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s = "aeiou";
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    char c;
    cin >> c;

    bool check = false;
    for(int i = 0; i < 5; ++i){
        if(c == s[i])
        check = true;
    }
    cout << (check ? "vowel" : "consonant") << endl;

    return 0;
}