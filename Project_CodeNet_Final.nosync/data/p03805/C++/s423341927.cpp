#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <utility>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define SUM(n) ((n)+1)*(n)/2
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = (1e9)+7;
#define all(v) v.begin(),v.end()
using namespace std;
using pii = pair<int,int>;
typedef vector<int> vit;

vit edge[10];
bool isvisited[10] = {false};
int n, m;

int bfs(int x, int ans, int sum){
  if(isvisited[x]){
    return ans;
  }
  if(sum == n){
    return ans + 1;
  }
  isvisited[x] = true;
  rep(i, edge[x].size()){
    ans = bfs(edge[x][i], ans, sum + 1);
  }
  isvisited[x] = false;
  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m;
  int a, b;
  rep(i,m){
    cin >> a >> b;
    edge[a].pu(b);
    edge[b].pu(a);
  }
  cout << bfs(1, 0, 1) << '\n';
  return 0;
}
