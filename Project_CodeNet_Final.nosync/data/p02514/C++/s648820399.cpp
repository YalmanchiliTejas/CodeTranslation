#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <memory.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int,P> PP;
const int INF = 1 << 29;

int w, h;
int memo[110][110];
int field[110][110];

int main(){
  while(cin >> w >> h && (w || h)){
    int sx, sy, gx, gy;
    fill(&memo[0][0], &memo[109][109] + 1, INF);
    memset(field, -1, sizeof(field));
    int l = 0;
    rep(i, h){
      rep(j, w){
	char ch;
	cin >> ch;
	if(ch == 'S'){
	  sx = j;
	  sy = i;
	}else if(ch == 'G'){
	  gx = j;
	  gy = i;
	}else if( ch == '.'){
	  field[i][j] = -1;
	}else{
	  cin.putback(ch);
	  cin >> field[i][j];
	  l = max(field[i][j], l);
	}
      }
    }

    
    field[sy][sx] = 0;
    field[gy][gx] = l + 1;
    
    priority_queue<PP, vector<PP>, greater<PP> > que;
    que.push(PP(0, P(sy, sx)));
    memo[sy][sx] = 0;

    while(!que.empty()){
      PP pp = que.top();
      que.pop();
      int x = pp.second.second;
      int y = pp.second.first;
      int cost = pp.first;
      int nxt = field[y][x] + 1;
      
      rep(i, h)rep(j, w){
	if(field[i][j] == nxt){
	  int dis = abs(i - y) + abs(j - x);
	  if(memo[i][j] > cost + dis){
	    memo[i][j] = cost + dis;
	    que.push(PP(memo[i][j], P(i, j)));
	  }
	}
      }
    }
    cout << memo[gy][gx] << endl; 
  }
  return 0;
}