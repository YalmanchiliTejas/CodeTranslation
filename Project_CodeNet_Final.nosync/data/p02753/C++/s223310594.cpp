#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    string s;
    cin >>  s;
    map<char,int> m;
    for ( int i = 0; i < 3; i++ ) {
        m[s[i]]++;
    }
    
    return m.size() != 1;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}