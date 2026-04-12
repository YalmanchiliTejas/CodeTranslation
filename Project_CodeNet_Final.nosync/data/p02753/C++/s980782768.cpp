//158 A - Station and Bus 2020/3/7

#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    string s; cin >> s;
    bool ans = true;
    if (s[0]==s[1] && s[1]==s[2]) ans = false;
    cout << (ans ? "Yes" : "No" ) << endl;
}