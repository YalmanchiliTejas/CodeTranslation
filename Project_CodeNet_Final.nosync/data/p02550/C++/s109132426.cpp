#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
struct INF { template<class T> operator T() { return numeric_limits<T>::max() / 2; } } INF;

int mx = 60;

int main(){

    ll n, x, m;
    cin >> n >> x >> m;

    V<V<ll>> to(mx, V<ll>(m));
    V<V<ll>> sum(mx, V<ll>(m));

    rep(i,m) {
        to[0][i] = i*i % m;
        sum[0][i] = i;
    }

    rep(i,mx-1)rep(j,m) {
        to[i+1][j] = to[i][to[i][j]];
        sum[i+1][j] = sum[i][j] + sum[i][to[i][j]];
    }

    ll cur = x, ans = 0;
    for(ll i = mx-1; i >= 0; i--) {
        if(n>>i & 1) {
            ans += sum[i][cur];
            cur = to[i][cur];
        }
    }

    cout << ans << endl;
}