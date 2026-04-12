#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<bool,bool> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

int n;
vector<int> g[111111];

P dfs(int v,int pre){
  if(g[v].size()==1&&g[v][0]==pre){
    return P(true,false);
  }
  int cnt=0;
  for(int nv: g[v]){
    if(nv!=pre){
      P tmp=dfs(nv,v);
      if(!tmp.fi)return P(false,false);
      if(!tmp.se)cnt++;
    }
  }
  return P(cnt<=1,cnt==1);
}

int main(){
	cin.sync_with_stdio(false);
  cin>>n;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  P res=dfs(0,-1);
  if(res.fi&&res.se)cout<<"Second"<<endl;
  else cout<<"First"<<endl;
	return 0;
}
