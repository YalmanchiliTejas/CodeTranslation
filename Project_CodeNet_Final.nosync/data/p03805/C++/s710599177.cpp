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
  bool G[n][n];
  rep(i,n)rep(j,n)G[i][j]=false;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a][b]=true;
    G[b][a]=true;
  }
  vector<int>p(n);
  rep(i,n)p[i]=i;
  
  int ans=0;
  do{
    if(p[0]!=0)break;
    bool ok=true;
    for(int i=1;i<n;i++){
      if(!G[p[i-1]][p[i]])ok=false;
    }
    if(ok)ans++;
  }while(next_permutation(all(p)));
       
  cout << ans << endl;
  return 0;     
}
