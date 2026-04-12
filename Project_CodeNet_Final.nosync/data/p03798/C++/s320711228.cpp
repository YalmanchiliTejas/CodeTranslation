#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "../include/debug.hpp"
#else
#define debug(...) 42
#endif

const string ini = "SWWSS";
int N;
string s;

char trans(char animal, char saying) {
    if (animal == 'S') return saying;
    return saying == 'o' ? 'x' : 'o';
}

string solve(string t) {
    for (int i=0; i<N-2; ++i) {
        if (trans(t[i], s[i]) == 'o') {
            t[i+1] = t[(i-1+N)%N];
        } else {
            t[i+1] = (t[(i-1+N)%N] == 'S' ? 'W' : 'S');
        }
    }
    for (int i=N-2; i<=N-1; ++i) {
        if (trans(t[i], s[i]) == 'o' && t[(i-1+N)%N] != t[(i+1+N)%N]) return "";
        if (trans(t[i], s[i]) == 'x' && t[(i-1+N)%N] == t[(i+1+N)%N]) return "";
    }
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> s;

    string t = "";
    for (int i=0; i<N-2; ++i) t += ".";

    for (int i=0; i<4; ++i) {
        string res = solve(ini[i]+t+ini[i+1]);
        if (res != "") {
            cout << res << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}