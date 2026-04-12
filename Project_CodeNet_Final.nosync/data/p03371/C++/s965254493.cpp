#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}

bool is_res(int n){
    map<int,int> p;
    for(int i = 2;i*i<=n;i++){
        while(n%i == 0){
            n/=i;
            p[i]++;
        }
    }
    if(n > 1)p[n]++;
    ll res = 1;
    for(auto a:p){
        res *= a.second + 1;
    }
    if(res == 8)return true;
    return false;
}
signed main()
{   
    gearup;
    ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    ll res;
    res = min(a*x+b*y,2*c*max(x,y));
    ll z = min(x,y);
    res = min(res,2*c*z+a*(x-z)+b*(y-z));
    cout << res << endl;
}