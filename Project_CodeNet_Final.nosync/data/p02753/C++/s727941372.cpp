#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    string s;
    cin >> s;
    string ans = "";
    bool existA = false;
    bool existB = false;
    rep(i, 3) {
        if(s.at(i) == 'A') existA = true;
        if(s.at(i) == 'B') existB = true;    
    }
    if(existA && existB) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
    return 0;
}