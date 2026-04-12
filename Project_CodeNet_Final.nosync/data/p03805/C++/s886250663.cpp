#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
ll gcd(ll a,ll b){if(a<b)swap(a,b);ll c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int n;
int sum=0;
vector<vector<int>> g(10);

void solve(int u,vector<bool> m){
  bool f=0;
  m[u]=1;
  rep(i,n){
    if(!(m[i])) f=1;
  }
  if(f){
    rep(i,g[u].size()){
      int v=g[u][i];
      if(!(m[v])){
        solve(v,m);
      }
    }
  }else sum++;
}

int main(){
  int m; cin>>n>>m;
  rep(i,m){
    int a,b; cin>>a>>b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  vector<bool> k(n,0);
  solve(0,k);
  cout<<sum<<endl;

  return 0;
}
