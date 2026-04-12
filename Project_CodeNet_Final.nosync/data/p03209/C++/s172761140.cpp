#include <iostream>

using namespace std;
using ll = long long;
ll full[51];
ll len[51];

ll cnt(int lv, ll x) {
    ll pl = len[lv - 1];
    if (lv == 0) return x;
    if (x == 0) return 0;
    if (x <= pl + 1) return cnt(lv - 1, x - 1);
    if (x == pl + 2) return full[lv - 1] + 1;
    if (x < pl * 2 + 2) return full[lv - 1] + 1 + cnt(lv - 1, x - pl - 2);
    return full[lv];
}

int n;
ll gx;

int main(){
    cin >> n >> gx;
    full[0] = 1;
    len[0] = 1;
    for (int i = 1; i <= n; ++i) {
        full[i] = 1 + full[i - 1] * 2;
        len[i] = 3 + len[i - 1] * 2;
    }

    cout << cnt(n, gx) << endl;
}