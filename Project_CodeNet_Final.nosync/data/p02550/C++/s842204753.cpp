//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define in(x, l, r) (ll)(l) <= (x) && (x) < (ll)(r)

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<int> num_appeared(100000,0);
    ll ans = 0;
    ll tmp = X;
    ll count = 0;
    while (count < N) {
        ans += tmp;
        count++;
        num_appeared[tmp] = 1;
        tmp = (tmp * tmp) % M;
        if (num_appeared[tmp] == 1) break;
    }
//    cout << 1 << endl;
    int loop_length = 0;
    ll sum_loop = 0;
    while (count < N) {
        loop_length++;
        ans += tmp;
        count++;
        sum_loop += tmp;
        num_appeared[tmp] = 2;
        tmp = (tmp * tmp) % M;
        if (num_appeared[tmp] == 2) break;        
    }
    ans += (N - count) / max(loop_length,1) * sum_loop;
    count += (N - count) / max(loop_length,1) * loop_length;
    while (count < N) {
        ans += tmp;
        count++;
        tmp = (tmp * tmp) % M;
    }
    cout << ans << endl;
}