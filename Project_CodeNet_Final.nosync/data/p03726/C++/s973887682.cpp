#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

const int MAX_N=1e5+10;

int N;
vector<vector<int>> G(MAX_N);
vector<bool> odd(MAX_N,false),even(MAX_N,false);
bool ok=false;

void dfs(int v,int p){
    int a=0,b=0;
    if (p>=0&&G[v].size()==1) odd[v]=true;
    for (auto nv:G[v]){
        if (nv==p) continue;
        dfs(nv,v);
        if (odd[nv]) ++a,even[v]=true;
        if (even[nv]){
            ++b;
            if (G[v].size()<3) odd[v]=true;
        }
    }
    if (p>=0&&b==(int)G[v].size()-1) odd[v]=true;
    if (p<0&&b==G[v].size()) ok=true;
    if (a>=2) ok=true;
    if (b>=2&&G[v].size()<3) ok=true;
    if (p<0&&G[v].size()==1&&odd[v]) ok=true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i,N-1){
        int a,b; cin >> a >> b; --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1);
    if (ok) cout << "First" << endl;
    else cout << "Second" << endl;
}