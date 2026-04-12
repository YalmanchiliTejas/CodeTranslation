#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ret = 800 * n;
    ret -= 200 * (n / 15);
    cout << ret << "\n";
    return 0;
}