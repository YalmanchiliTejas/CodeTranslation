#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

int dfs(int, bool[]);

int route[9][9];
int n, m;

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> m;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    route[a][b] = route[b][a] = 1;
  }

  bool visited[n + 1] = {false};
  visited[1] = true;
  print(dfs(1, visited));

  return 0;
}

int dfs(int v, bool visited[]) {
  bool newVisited[n + 1];

  bool all = true;
  repl(i, 1, n + 1) {
    newVisited[i] = visited[i];
    if(!visited[i]) all = false;
  }

  if(!all) {
    int cnt = 0;
    bool ok = false;
    repl(i, 1, n + 1) {
      if (route[v][i] == 1 && !newVisited[i]) {
        newVisited[i] = true;
        cnt += dfs(i, newVisited);
        newVisited[i] = false;
      }
    }
    return cnt;
  } else {
    return 1;
  }
}