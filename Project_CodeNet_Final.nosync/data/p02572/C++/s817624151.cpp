//vec[i]の範囲外エラー表示
#define _GLIBCXX_DEBUG
//includeとusing
#include <bits/stdc++.h>
using namespace std;
//型名省略
using ll = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using pll = pair<ll, ll>;
//定数
const ll INF = 1e9;
const ll MOD = 1e9+7;
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define all(A) A.begin(), A.end()
//入力
ll llin() {ll x; cin >> x; return x;}
string stin() {string s; cin >> s; return s;}
vl vlin(ll n) {vl a(n); rep(i,n){cin >> a[i];} return a;}
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}


//main関数
int main() {
    ll n = llin();
    vl a(n);
    rep(i,n){
        cin >> a[i];
    }

    vl sum(n,a[0]);
    rep(i,n - 1){
        sum[i + 1] = (sum[i] + a[i + 1]) % MOD;
    }
    ll ans = 0;
    rep(i,n - 1){
        ans += (sum[i] * (a[i + 1])) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

