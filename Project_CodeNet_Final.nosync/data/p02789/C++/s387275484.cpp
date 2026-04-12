#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N, M;
    cin >> N >> M;
    
    return N==M;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}