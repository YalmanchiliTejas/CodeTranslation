#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    string s;
    cin >> s;
    bool ok = true;
    if(s.length() != 3){
        ok = false;
    }
    rep(i,3){
        if(s[i] != 'A' && s[i] != 'B'){
            ok = false;
        }
    }
    if(s == "AAA" || s == "BBB"){
        ok = false;
    }
    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}