#include <bits/stdc++.h>
using namespace std;
char c;
string def = "aeiou";
int main(){
    cin >> c;
    cout << ((def.find(c)!=-1)? "vowel" : "consonant") << endl;
}