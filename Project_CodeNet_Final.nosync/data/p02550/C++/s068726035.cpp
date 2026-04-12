#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

ll power(ll x, ll pw, ll mod) {
    ll res = 1;
    x = x % mod;  // if it x >= p
    while (pw > 0) {
        if (pw & 1)
            res = (res*x) % mod;
        pw /= 2;
        x = (x*x) % mod;
    }
    return res;
}
ll modInverse(ll n, ll p) {
    return power(n, p-2, p) % p; // Fermat's little theorem
}

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> bucket(m, 0);
    ll pre = x;
    bucket[x] += 1;
    ll period = -1;
    vector<ll> pos(m, -1);
    pos[x] = 0;
    ll ans = x;
    vector<ll> rec(m, -1);
    rec[0] = x;
    for(int i = 1; i < n; i++) {
        ll cur = (pre*pre) % m;
        if (pos[cur] == -1) {
            bucket[cur] += 1;
            pos[cur] = i;
            rec[i] = cur;
            ans += cur;
        } else {
            period = i-pos[cur];
            //cout << "period " << period << endl;
            int beg = pos[cur];
            ll remain = n-i;
            ll repeat_sum = 0;
            for(int j = beg; j < i; j++)
                repeat_sum += rec[j];
            ll repeat_times = remain / period;
            ans += repeat_times * repeat_sum;
            ll rem = remain % period;
            for(int j = beg; j < beg+rem; j++) {
                ans += rec[j];
            }
            //cout << "remain " << remain << endl;
            break;
        }
        pre = cur;
    }
    cout << ans << endl;


    return 0;
}
