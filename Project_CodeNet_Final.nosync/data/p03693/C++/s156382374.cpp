#include <bits/stdc++.h>
using namespace std;  // NOLINT
using LL = int64_t;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a * 100 + b * 10 + c) % 4) cout << "NO\n";
    else cout << "YES\n";
}
