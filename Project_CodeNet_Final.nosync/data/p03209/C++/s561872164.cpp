#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

V<ll> len, pat;

ll rec(ll n, ll x){
    if(n == 0){
        if(x == 1) return 1;
        else return 0;
    }
    if(x == 1) return 0;
    if(x == len[n]) return pat[n];

    ll ans = 0;
    if(len[n] / 2 + 1 <= x){
        ans += pat[n - 1] + 1 + rec(n - 1, x - len[n] / 2 - 1);
    }
    if(len[n] / 2 + 1 > x){
        ans += rec(n - 1, x - 1);
    }
    return ans;
}

int main() {
    ll n, x; cin >> n >> x;

    len.resize(n + 1);
    pat.resize(n + 1);
    len[0] = pat[0] = 1;
    for(int i = 1; i <= n; i++){
        len[i] = len[i - 1] * 2 + 3;
        pat[i] = pat[i - 1] * 2 + 1;
    }
    cout << rec(n, x) << endl;

}
