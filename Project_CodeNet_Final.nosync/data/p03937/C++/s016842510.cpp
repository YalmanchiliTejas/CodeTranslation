#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "Possible";
const string NO  = "Impossible";

int H,W;
string s[20];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void compute() {
  deque<int> deq;
  if( s[0][0] == '.' || s[H-1][W-1] == '.' ) {
    puts(NO.c_str());
    return;
  }
  s[0][0] = '.';
  deq.push_back(0);
  while( !deq.empty() ) {
    int cur = deq.front(); deq.pop_front();
    int x = cur % W, y = cur / W;
    rep(i,2) {
      int nx = x + dx[i], ny = y + dy[i];
      if( !( 0 <= nx && nx < W && 0 <= ny && ny < H ) ) continue;
      if( s[ny][nx] == '.' ) continue;
      deq.push_back(nx+ny*W);
      s[ny][nx] = '.';
      break;
    }
  }
  bool found = false;
  rep(i,H) rep(j,W) if( s[i][j] == '#' ) found = true;
  puts( !found ? YES.c_str() : NO.c_str());
}



int main() {
  cin >> H >> W;
  rep(i,H) cin >> s[i];
  compute();
  return 0;
}
