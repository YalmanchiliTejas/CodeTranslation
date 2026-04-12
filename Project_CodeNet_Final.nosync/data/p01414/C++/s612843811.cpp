#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define ITER(c) __typeof((c).begin())
#define PB(e) push_back(e)
#define FOREACH(i, c) for(ITER(c) i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define PARITY(n) ((n) & 1)

typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-10;

int dist[1 << 16];
int N;
int W[16], H[16];
char goal[4][4];


int main(){

  cin >> N;
  REP(i, N) cin >> H[i] >> W[i];
  REP(i, 4)REP(j, 4){
    cin >> goal[i][j];
    if(goal[i][j] == 'R') goal[i][j] = 0;
    if(goal[i][j] == 'G') goal[i][j] = 1;
    if(goal[i][j] == 'B') goal[i][j] = 2;
  }

  
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0, 0));
  fill(dist, dist + (1 << 16), INF);
  dist[0] = 0;
  
  while(!que.empty()){
    int cost = que.top().first;
    int mask = que.top().second;
    que.pop();
    if(cost > dist[mask]) continue;

    if(mask == 0xFFFF){
      cout << cost << endl;
      return 0;
    }
    
    
    REP(i, N){
      for(int h1 = -H[i] + 1; h1 < 4; h1++){
        for(int w1 = -W[i] + 1; w1 < 4; w1++){
          int h2 = h1 + H[i];
          int w2 = w1 + W[i];
          int nmaskc[3] = {0,0,0};
          
          int nmaskn = 0;
          
          REP(r, 4)REP(c, 4){
            if(h1 <= r && r < h2 && w1 <= c && c < w2){
              nmaskc[goal[r][c]] |= 1 << (r * 4 + c);
            }else{
              nmaskn |= mask & (1 << (r * 4 + c));
            }
          }

          REP(color, 3){
            int nmask = nmaskc[color] | nmaskn;
            if(dist[nmask] > cost + 1){
              dist[nmask] = cost + 1;
              que.push(P(cost + 1, nmask));
            }
          }
        }
      }
    }
  }
  assert(false);
  return 0;
}