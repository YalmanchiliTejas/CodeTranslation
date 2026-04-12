#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H, W; cin >> H >> W;
  VS vs(H);
  REP(y,H) cin >> vs[y];
  if(vs[0][0] != '#' || vs[H-1][W-1] != '#'){
	cout << "Impossible" << endl;
	return 0;
  }

  int x = 0, y = 0;
  while(true){
	int b = -1;
	if(x+1<W && vs[y][x+1] == '#')
	  b = 0;
	if(y+1<H && vs[y+1][x] == '#')
	  b = (b == -1? 1: -1);
	if(b < 0) break;
	x += dx[b], y += dy[b];
  }
  int cnt = 0;
  REP(y,H) REP(x,W) cnt += vs[y][x]=='#';
  cout << (x==W-1&&y==H-1&&cnt==H+W-1? "Possible": "Impossible") << endl;

  return 0;
}
