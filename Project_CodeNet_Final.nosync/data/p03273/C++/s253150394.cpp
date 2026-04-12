#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};

template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct Timer{
    chrono::system_clock::time_point start, end;
    Timer(){ start = chrono::system_clock::now(); }
    ~Timer(){
        end = chrono::system_clock::now();
        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr<<"time : "<<msec<<" ms"<<endl;
    }
};




signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    // Timer TM;
    
    
    ll h,w;
    cin>>h>>w;
    map<ll,ll> H,W;
    string a[110];
    char b[110][110];
    rep(i,h){
        cin>>a[i];
        // rep(j,w){
        //     cout<<a[i][j]<<endl;
        // }
    }
    rep(i,h){
        if(a[i][0]=='#') continue;
        bool ok=true;
        rep(j,w){
            if(a[i][j]=='#') ok=false;
        }
        if(ok) H[i]++;
    }
    rep(i,w){
        if(a[0][i]=='#') continue;
        bool ok=true;
        rep(j,h){
            if(a[j][i]=='#') ok=false;
        }
        if(ok) W[i]++;
    }
    ll cnti=0;
    ll cntj=0;
    ll cj=0;
    rep(i,h){
        if(H[i]>0) continue;
        rep(j,w){
            if(W[j]>0) continue;
            b[cnti][cntj]=a[i][j];
            cntj++;
        }
        cnti++;
        cj=cntj;
        cntj=0;
    }
    rep(i,cnti){
        rep(j,cj){
            cout<<b[i][j];
        }
        cout<<endl;
    }


    return 0;
}
