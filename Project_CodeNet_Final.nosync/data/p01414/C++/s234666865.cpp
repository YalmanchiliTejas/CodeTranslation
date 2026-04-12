#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <bitset>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1<<29)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int N;
int C[4][4];
vector<pi>Stamp;
int dist[1<<16];

int f(int h, int w, int sx, int sy, int c, int S){
  //  cout << h << " " << w << " " << sx << " " << sy << " " << c << " " << S << endl;
  for(int i=max(sx, 0);i<min(sx+h, 4);i++){
    for(int j=max(sy, 0);j<min(sy+w, 4);j++){
      int pos = i*4+j;
      if(C[i][j] == c){
	S |= 1<<pos;
      }else{
	S &= ((1<<16)-1) - (1<<pos);
      }
    }
  }
  //  cout << h << " " << w << " " << sx << " " << sy << " " << c << " " << S << endl;  
  return S;
}

int main()
{
  cin >> N;
  Stamp.resize(N);
  for(auto &stamp: Stamp) cin >> stamp.first >> stamp.second;
  rep(i, 4){
    string s;
    cin >> s;
    rep(j, 4){
      if(s[j] == 'R')
	C[i][j] = 0;
      if(s[j] == 'G')
	C[i][j] = 1;
      if(s[j] == 'B')
	C[i][j] = 2;
    }
  }
  fill(dist, dist+(1<<16), INF);
  queue<pi>Q;
  Q.push(pi(0, 0));
  dist[0] = 0;
  while(!Q.empty()){
    pi p = Q.front(); Q.pop();
    int state = p.second;
    int cost = p.first;
    //    cout << static_cast<bitset<16> >(state) << " " << cost << endl;
    if(state == (1<<16) - 1){
      cout << cost << endl;
      break;
    }    
    if(dist[state] < cost) continue;
    for(auto &stamp: Stamp){
      int H = stamp.first, W = stamp.second;
      for(int sx = -H+1; sx < 4; sx++){
	for(int sy = -W+1; sy < 4; sy++){
	  for(int color=0;color<3;color++){
	    int next_state = f(H, W, sx, sy, color, state);
	    if(cost + 1 < dist[next_state]){
	      dist[next_state] = cost + 1;
	      Q.push(pi(dist[next_state], next_state));
	    }
	  }
	}
      }
    }
  }
  return 0;
}