#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, a, n) for(int i=(a); i<(n); i++)

int main() {
    string s;
    cin >> s;
    rep(i, s.size()-1) {
        if(s[i] != s[i+1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
