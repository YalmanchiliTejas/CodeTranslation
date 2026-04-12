// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }
template< typename T > istream &operator>>(istream &is, vector< T > &v) { for(T &in : v) is >> in; return is; }

int n;string s;
string check(string t){
    for(int i=1;i<=n+1;i++){
        if(t[i]=='S'&&s[i]=='o'){
            t+=t[i-1];
        }
        if(t[i]=='S'&&s[i]=='x'){
            t+=(t[i-1]=='S'? 'W':'S');
        }
        if(t[i]=='W'&&s[i]=='o'){
            t+=(t[i-1]=='S'? 'W':'S');
        }
        if(t[i]=='W'&&s[i]=='x'){
            t+=t[i-1];
        }
    }
    return t;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    
    cin>>n>>s;
    s+=s[0];
    vector<string> t(4);
    t[0]="SS";
    t[1]="SW";
    t[2]="WS";
    t[3]="WW";
    vector<string> u(4);
    rep(i,4){
        u[i]=check(t[i]);
        // cout<<u[i]<<endl;
        
        if(u[i].substr(0,2)==u[i].substr(u[i].size()-2,2)){
            rep(j,u[i].size()-2){
                cout<<u[i][j];
            }
            cout<<endl;
            return 0;
        }
        
    }
    cout<<-1<<endl;
    
}