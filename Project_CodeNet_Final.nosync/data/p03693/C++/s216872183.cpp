#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if ((10 * g + b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}