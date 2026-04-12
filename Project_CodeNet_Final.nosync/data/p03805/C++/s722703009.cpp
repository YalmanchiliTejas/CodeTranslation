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
ll gcd(ll a,ll b){if(a<b)swap(a,b);while((a%b)!=0){a=b;b=a%b;}return b;}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

vector<vector<int>> g(8);
int sum=0;
int n;

void solve(int d,vector<bool>& c,int k){
  k++;
  if(k==n) sum++;
  c[d]=1;
  rep(i,g[d].size()){
    int to=g[d][i];
    if(c[to]) continue;
    vector<bool> C(n);
    rep(i,n){
      if(c[i]) C[i]=1;
      else C[i]=0;
    }
    solve(to,C,k);
  }
}

int main(){
  int m; cin>>n>>m;
  rep(i,m){
    int a,b; cin>>a>>b;
    a--;b--;
    g[a].pb(b);g[b].pb(a);
  }

  vector<bool> c(n,0);
  solve(0,c,0);
  cout<<sum<<endl;

  return 0;
}
