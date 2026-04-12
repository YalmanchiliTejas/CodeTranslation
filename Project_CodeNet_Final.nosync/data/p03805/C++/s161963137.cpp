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
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main()
{   
    gearup;
    int n,m; cin >> n >> m;
    vvl a(n,vl(n,0));
    rep(i,m){
        int x,y; cin >> x >> y;
        x--;y--;
        a[x][y]=1;
        a[y][x]=1;
    }
    vector<int> b(n);
    rep(i,n)b[i]=i;
    //debug(b);
    ll res = 0;
    do{
        ll is_res = true;
        if(a[0][b[1]] == 0)is_res=false;
        rep1(i,n-1){
            if(a[b[i]][b[i+1]] == 0)is_res = false;
        }
        if(is_res)res++;
    }while(next_permutation(b.begin()+1,b.end()));
    cout << res << endl;
}
