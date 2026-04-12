#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

vector<int> v[11];
vector<bool> used(11,false);
int n,m;
int ans=0;

void dfs(int x, int cnt){
  if(cnt==n){ ans++; return; }
  for(auto to:v[x])if(!used[to]){
    used[to]=true;
    dfs(to, cnt+1);
    used[to]=false;
  }
}

int main(){
  cin >> n >> m;
  rep(i,m){ 
    int a,b; cin>>a>>b; a--; b--;
    v[a].emplace_back(b);
    v[b].emplace_back(a);
  }
  used[0]=true;
  dfs(0,1);
  
  cout << ans << endl;
  return 0;
}