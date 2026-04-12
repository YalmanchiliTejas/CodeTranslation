#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    string S;
    cin >> S;
    for ( int i = 0; i < S.size()-1; i++ ) {
        if ( S.substr(i,2) == "AC" ) return true;
    }
    return false;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}