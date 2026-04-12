#include<iostream>
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n)
#define EACH(x,a) for(auto& (x):(a))
#define ALL(obj) (obj).begin(),(obj).end()
#define Yes(n) cout<<((n)?"Yes":"No")<<endl;
using namespace std;
using ll=long long;
const int INF=1e9;
const ll LINF=1e18;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int N, M;
bool adj[10][10]; // 0-origin
bool visited[10];
int vcount=0;
int ans=0;

void dfs(int from){
  visited[from] = true;
  ++vcount;

  if(vcount==N) ++ans;
  else REP(i,N) if(!visited[i] && adj[from][i]) dfs(i);

  visited[from] = false;
  --vcount;
  return;
}


int main(){
  cin>>N>>M;
  REP(i,N) REP(j,M) adj[i][j]=false;
  REP(i,M){
    int a,b; cin>>a>>b;
    adj[a-1][b-1]=adj[b-1][a-1]=true;
  }

  dfs(0);

  cout<<ans<<endl;
  return 0;
}
