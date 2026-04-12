#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=998244353;
const int INF=1e9;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vvl G;


void dfs(int v,vector<bool> &seen,int  &res){
  bool end=true;
  rep(i,seen.size())if(!seen[i] &&i!=v)end=false;
  if(end){
    res++;
    return;
  }
  seen[v]=true;
  for(auto nv:G[v]){
    if(seen[nv])continue;
    dfs(nv,seen,res);
  }
  seen[v]=false;
}
         
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,m;
  cin >> n >> m;
  G.resize(n); 
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool>seen(n,false);
  int res=0;
  dfs(0,seen,res);
  cout << res << endl;
  return 0;     
}
