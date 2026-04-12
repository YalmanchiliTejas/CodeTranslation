#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int a, b, c, d, n, x, y;

    auto Yes = [&](bool t){
        cout << (t ? "Yes" : "No") << endl;
    };
    auto YES = [&](bool t){
        cout << (t ? "YES" : "NO") << endl;
    };
    auto tri = [&](bool t, string a, string b){
        cout << (t ? a : b) << endl;
    };

    cin >> a >> b >> c;
    YES((a * 100 + b * 10 + c) % 4 == 0);
}
