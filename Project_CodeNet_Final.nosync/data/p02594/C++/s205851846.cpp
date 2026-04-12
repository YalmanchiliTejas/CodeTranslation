#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll X;
    cin >> X;
    if ( X >= 30 ) return true;
    return false;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}