#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (ll i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
 
ll n, x, m;
 
int order[100000];
ll sum[100000];
 
int main() {
    cin >> n >> x >> m;
    ll s = 0;
    int loop_b = -1, loop_e = -1;
    reps(i, n) {
        if (order[x] != 0) {
            loop_b = order[x];
            loop_e = i;
            break;
        }
        s += x;
        order[x] = i;
        sum[i] = s;
        x = (x * x) % m;
    }
    ll ans = s;
    if (loop_b != -1) {
        ll a = (n - loop_e + 1) % (loop_e - loop_b);
        ans += (sum[loop_e - 1] - sum[loop_b - 1]) * ((n - loop_e + 1) / (loop_e - loop_b)) +
               (sum[loop_b + a - 1] - sum[loop_b - 1]);
    }
    cout << ans << endl;
    return 0;
}