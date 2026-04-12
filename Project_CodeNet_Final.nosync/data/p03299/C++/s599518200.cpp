#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
const int MOD = 1e9 + 7;
int n, h[N];
int qpow(int x, int k) {
    int r = 1;
    while(k) {
        if(k & 1) r = (ll)r * x % MOD;
        x = (ll)x * x % MOD;
        k >>= 1;
    }
    return r;
}
typedef pair<int, int> pii;
pii dfs(int l, int r) {
    int mn = 2e9, mc = 0;
    for(int i = l; i <= r; i++) {
        if(h[i]) {
            if(mn == h[i]) mc++;
            else if(mn > h[i]) mc = 1;
            mn = min(mn, h[i]);
        }
    }
    // printf("mc:%d mn:%d\n", mc, mn);
    vector<pii> res;
    int st = -1, t = 0;
    for(int i = l; i <= r; i++) {
        h[i] -= mn;
        if(h[i]) {
            if(st == -1) st = i, t = 1;
            else {
                t++;
            }
        } else {
            if(t) {
                res.push_back(dfs(st, st + t - 1));
                t = 0;
                st = -1;
            }
        }
    }
    if(t) {
        res.push_back(dfs(st, st + t - 1));
    }
    ll o1 = qpow(2, mc), o2 = qpow(2, mn);
    ll r1 = o1, r11 = o2 - 2, ret2 = o2;
    for(pii p : res) {
        ret2 = ret2 * p.second % MOD;
        r1 = r1 * (p.first + p.second) % MOD;
        r11 = r11 * p.second % MOD;
    }
    // printf("%d  %d  mn:%d  mc:%d  ret1:%d  ret2:%d\n", l, r, mn, mc, ret1, ret2);
    return pii((r1 + r11) % MOD, ret2);
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    pii res = dfs(0, n - 1);
    cout << res.first % MOD << endl;
    return 0;
}