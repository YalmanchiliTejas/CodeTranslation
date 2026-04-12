#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    char c;
    cin >> c;
    string s = "aiueo";
    bool ok = false;
    for(int i=0;i<5;i++) if(c==s[i]) ok = true;
    if(ok) cout << "vowel" << endl;
    else cout << "consonant" << endl; 

}