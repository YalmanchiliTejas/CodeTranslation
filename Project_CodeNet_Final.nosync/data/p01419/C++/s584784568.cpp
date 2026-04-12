//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int H, W, M;
int idx(int x, int y){
  return y*W+x;
}
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> H >> W >> M;
  VS vs(H);
  REP(i,H) cin >> vs[i];
  VVI cost(H, VI(W)), on(H, VI(W)), off(H, VI(W));
  REP(y,H) REP(x,W) cin >> cost[y][x];
  REP(y,H) REP(x,W) cin >> on[y][x];
  REP(y,H) REP(x,W) cin >> off[y][x];
  vector<PII> task(M);
  REP(i,M) cin >> task[i].second >> task[i].first;

  vector<PII> path;
  path.PB(task[0]);
  for(int i=0;i+1<M;++i){
	bool vis[50][50];
	fill((bool*)vis, (bool*)vis+50*50, false);
	PII par[50][50];

	queue<PII> q;
	q.push(task[i]);
	vis[task[i].second][task[i].first] = true;
	while(!vis[task[i+1].second][task[i+1].first]){
	  PII p = q.front(); q.pop();
	  REP(i,4){
		int tx = p.first + dx[i], ty = p.second + dy[i];
		if(tx < 0 || W <= tx || ty < 0 || H <= ty || vis[ty][tx] || vs[ty][tx] == '#') continue;
		vis[ty][tx] = true;
		par[ty][tx] = p;
		q.push(MP(tx,ty));
	  }
	}

	vector<PII> tmp;
	PII p = task[i+1];
	while(p != task[i]){
	  tmp.PB(p);
	  p = par[p.second][p.first];
	}
	reverse(ALL(tmp));
	path.insert(path.end(), ALL(tmp));
  }

  bool flag[50][50];
  fill((bool*)flag, (bool*)flag+50*50, false);
  LL ans = 0;
  for(int i=0;i<SZ(path);++i){
	int x = path[i].first, y = path[i].second;
	if(!flag[y][x]){
	  flag[y][x] = true;
	  ans += on[y][x];
	}
	int j;
	for(j=i+1;j<SZ(path);++j){
	  if(path[i] == path[j]){
		if((j-i)*cost[y][x] < on[y][x] + off[y][x])
		  ans += (j-i)*cost[y][x];
		else
		  ans += on[y][x] + off[y][x];
		break;
	  }
	}
	if(j == SZ(path)){
	  ans += off[y][x];
	}
  }

  cout << ans << endl;
  
  return 0;
}