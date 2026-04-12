#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll& b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll& b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
string s;
ll saiki(ll x, ll i, ll k) {
    if (i == 0) {
        if (x == n - 1 && k == 1)return 9;
        if (k == 0)return 1;
        if (x == n - 1)return 0;
        return saiki(x + 1, 0, k) + saiki(x + 1, 0, k - 1) * 9;
    }
    a = s[x] - '0';
    if (x == n - 1 && k == 1)return a;
    if (k == 0)return 1;
    if (a == 0)return saiki(x + 1, 1, k);
    return saiki(x + 1, 0, k) + saiki(x + 1, 0, k - 1) * (a - 1) + saiki(x + 1, 1, k - 1);
}
int main() {
    cin >> s >> k;
    n = s.length();
    if(n<k){
    	cout<<0<<endl;
    }
    else cout << saiki(0, 1, k) << endl;
}