#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

ll a[200010],sum[200010];

int main() {
    int n;cin>>n;
    rep(i,n) {
        cin>>a[i];
        sum[i+1] = (sum[i] + a[i])%MOD;
    }
    ll ans = 0;
    rep(i,n-1){
        ans = (ans + (a[i]*((sum[n]-sum[i+1]+MOD)%MOD))%MOD)%MOD;
    }
    if(ans < 0) ans = (ans + MOD) %MOD;
    cout<<ans<<endl;
}