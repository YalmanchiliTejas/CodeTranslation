#include <bits/stdc++.h>
using namespace std;
using lint         = long long;
constexpr lint inf = 1LL << 60;
constexpr lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes"
             << "\n";
    } else
        cout << "No"
             << "\n";
    return 0;
}