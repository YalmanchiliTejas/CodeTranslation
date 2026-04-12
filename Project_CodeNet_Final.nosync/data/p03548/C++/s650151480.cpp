#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << max(0, x / (y + z)) << endl;
}
