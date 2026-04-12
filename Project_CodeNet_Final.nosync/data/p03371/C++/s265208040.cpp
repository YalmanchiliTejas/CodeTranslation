#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repe(i,n) for (int i = 0; i <= (n); ++i)
#define repe1(i,n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(k,v) emplace_back(k,v)
#define ct(res) cout << res << "\n";
#define vi vector<int>
#define vl vector<ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;


void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

ll modPow(ll x, ll n) {
    if(n==0) return 1;
    ll res = modPow(x*x%MOD, n/2);
    if(n&1) res=res*x%MOD;
    return res;
}
ll mul(ll l, ll r) {
    ll ret =1;
    for(int i=0; i<l-r+1; ++i) {
        ret*=i+r;
        ret%=MOD;
    }
    return ret;
}
ll com(ll n, ll k) {
    ll ret1 = mul(n,n-k+1);
    ll ret2 = mul(k,1);
    ll ret3 = modPow(ret2, MOD-2);
    return ret1*ret3%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int ans = INF;
   int a,b,c,x,y; cin >> a >> b>> c >> x >>y;
   rep(i,max(x,y)+1) {
     int tmp = i*c*2;
     if(x>i) tmp += (x-i)*a;
     if(y>i) tmp += (y-i)*b;
     chmin(ans,tmp);
   }
   cout << ans << "\n";
}

