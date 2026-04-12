#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB")
        cout << "No"
             << "\n";
    else
        cout << "Yes"
             << "\n";
    return 0;
}