#include<iostream>
#include<climits>
#include<deque>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IINF (INT_MAX)
#define MAX_LEN 16
#define MAX_STATE (1<<16)

using namespace std;
typedef pair<int,int> ii;

const int DIFF = 3;
int N,H[MAX_LEN],W[MAX_LEN];
int bitmask[MAX_LEN][12][12][3][2]; // bitmask[type][y][x][color][bool] bool = false -> erase , true -> insert
bool mincost[MAX_STATE];
char G[4][4];
char color[] = {'R','G','B'};

inline void makeBitMask(){
  REP(y,-3,8)REP(x,-3,8)rep(stamp,N)rep(c,3)rep(cy,H[stamp])rep(cx,W[stamp]){
    int nx = x + cx;
    int ny = y + cy;
    if( !( 0 <= nx && nx < 4 && 0 <= ny && ny < 4 ) )continue;
    if( G[ny][nx] == color[c] )bitmask[stamp][y+DIFF][x+DIFF][c][true]  |= (1<<(nx+(ny*4)));
    else                       bitmask[stamp][y+DIFF][x+DIFF][c][false] |= (1<<(nx+(ny*4)));
  }
}

inline void compute(){
  for(bool& i : mincost)i = false;
  mincost[0] = true;
  deque<ii> deq;
  deq.push_back(ii(0,0));
  while(!deq.empty()){
    ii data = deq.front(); deq.pop_front();

    if( data.first == (MAX_STATE-1) ){
      cout << data.second << endl;
      break;
    }

    rep(stamp,N)rep(col,3)REP(y,-3,8)REP(x,-3,8){
      int state = ( data.first | bitmask[stamp][y+DIFF][x+DIFF][col][true] ) & (~bitmask[stamp][y+DIFF][x+DIFF][col][false]);
      if(mincost[state])continue;
      mincost[state] = true;
      deq.push_back(ii(state,data.second+1));
    }
  }
}

int main(){
  cin >> N;
  rep(i,N)cin >> H[i] >> W[i];
  rep(y,4)rep(x,4)cin >> G[y][x];
  makeBitMask();
  compute();
  return 0;
}