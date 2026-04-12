#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    VL a(n);
    rep(i,n) cin >> a[i];
    VL sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++) sum[i] = sum[i-1] + a[i];
    ll ans = 0;
    rep(i,n){
        ll s = sum[n-1] - sum[i];
        s %= mod;
        ans += s * a[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}