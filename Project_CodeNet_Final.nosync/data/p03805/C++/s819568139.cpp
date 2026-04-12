#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;


bool edge[8][8];
bool visit[8];
int ans=0;
int N;

void dfs(int x){
  if (visit[x]) return;
  visit[x]=true;
  bool work=true;
  REP(i, N) work = work && visit[i];
  if(work) ++ans;
  REP(i, N){
    if(edge[x][i]==1) dfs(i);
  }
  visit[x]=false;
  return;
}

int main(){
  int M;
  cin>>N>>M;
  REP(i, N)REP(j, N)edge[i][j]=false;
  int a, b;
  REP(i, M){
    cin>>a>>b;
    edge[a-1][b-1]=true;
    edge[b-1][a-1]=true;
  }

  REP(i, N) visit[i]=false;
  dfs(0);
  cout<<ans<<endl;

  return 0;
}
