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
    int x;
    cin >> x;
    if (x % 2 == 1 && x >= 3 && x <= 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}