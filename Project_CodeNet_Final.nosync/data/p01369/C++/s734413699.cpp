#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)

string s1 = "qwertasdfgzxcvb";
string s2 = "yuiophjklnm";

void solve(string s){
    int cur = 0;
    if(s2.find(s[0]) != string::npos) cur = 1;

    int ans = 0;
    for(int i = 1; i < (int)s.size(); i++) {
        if(cur == 0) {
            if(s2.find(s[i]) == string::npos) continue;
            ans++;
            cur = 1;
        } else {
            if(s1.find(s[i]) == string::npos) continue;
            ans++;
            cur = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    while(1){
        string s;
        cin >> s;
        if(s == "#") break;
        solve(s);
    }

    return 0;
}