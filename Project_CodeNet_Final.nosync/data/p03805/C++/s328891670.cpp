#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int N, M;
int mp[8][8]={0};
bool visited[8]={false};

int dfs(int n, int d){
  if(d==N-1) return 1;
  int ret = 0;
  rep(i,N){
    if(mp[n][i] && visited[i]==false){
      visited[i]=true;
      ret +=dfs(i, d+1);
      visited[i]=false;
    }
  }
  return ret;
}

int main()
{
  int res=0;
  cin >> N >> M;

  rep(i,M) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    mp[a][b]=1;
    mp[b][a]=1;
  }

  visited[0]=true;
  res = dfs(0,0);

  cout << res << endl;
}
