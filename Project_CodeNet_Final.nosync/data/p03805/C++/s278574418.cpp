#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


const int limit = 10;

bool graph[limit][limit];
bool visited[limit];

int N,M;

int dfs(int now, int depth) {
  if(visited[now]) return 0;
  if(depth==N) return 1;

  visited[now] = true;
  int ans = 0;

  for (int i = 0; i < N; ++i) {
   if(graph[now][i]) ans += dfs(i,depth+1);
  }

  visited[now] = false;

  return ans;
}

int main(){
  scanf("%d%d", &N,&M);
  int a[M],b[M];
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &a[i],&b[i]);
    --a[i];--b[i];
    graph[a[i]][b[i]] = true;
    graph[b[i]][a[i]] = true;
  }

  cout << dfs(0,1) << endl;


}