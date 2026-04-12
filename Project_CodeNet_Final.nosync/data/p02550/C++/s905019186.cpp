#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const double pi = 3.141592653589;
int mod = 1000000007;
/* global variables */
/* function */
/* main */
int main(){
    ll n, x, m;
    cin >> n >> x >> m;

    ll before_loop = 0, loop_size = 0, loop_sum = 0;
    vector<ll> sum(m + 1, 0);  // i回目の操作後のsumを格納 (a[i] = sum[i+1] - sum[i])
    map<ll, int> corresp; // keyが最初に出てくる場所
    int cnt = 0;
    ll ai = x;
    for (int i = 0; i <= m; i++) {
        cnt++;
        sum[i + 1] = sum[i] + ai;
        // ループに入る
        if (corresp.count(ai)) {
            before_loop = corresp[ai];
            loop_size = cnt - before_loop;
            loop_sum = sum[i + 1] - sum[before_loop];
            break;
        }
        corresp[ai] = cnt;
        ai = (ai * ai) % m;  // a[i + 1] = (a[i] * a[i]) % m
    }

    ll loop_times = (n - before_loop) / loop_size;
    ll after_loop = (n - before_loop) % loop_size;
    // A = {A1, A2, ..., An}
    // ループ前 + (ループ) + ループ後の残り
    // (ループ前 + ループ後の残り) + (ループ)
    ll ans = sum[before_loop + after_loop] + loop_sum * loop_times;
    cout << ans << '\n';
}
