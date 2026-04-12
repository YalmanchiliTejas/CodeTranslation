#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

enum direction{
  UP    = 0,
  RIGHT = 1,
  DOWN  = 2,
  LEFT  = 3
};

/*
 *   6
 *   2
 * 3 1 4
 *   5
 */

/* top and RIGHT */
int next_top[7][7][4];
int next_right[7][7][4];
int front[7][7];

void initDie(){
  front[1][3] = 2; front[1][2] = 4; front[1][4] = 5; front[1][5] = 3;
  front[2][1] = 3; front[2][3] = 6; front[2][4] = 1; front[2][6] = 4;
  front[3][1] = 5; front[3][2] = 1; front[3][5] = 6; front[3][6] = 2;
  for(int i = 4; i < 7; i++){
    for(int j = 1; j < 7; j++){
      if(i == j || i + j == 7) continue;
      int t = 7 - i;
      int l = 7 - j;
      front[i][j] = front[t][l];
    }
  }

  for(int t = 1; t < 7; t++){
    for(int r = 1; r < 7; r++){
      if(t == r || t + r == 7) continue;

      next_top[t][r][UP]     = front[t][r];
      next_top[t][r][LEFT]   = r;
      next_top[t][r][RIGHT]  = 7 - r;
      next_top[t][r][DOWN]   = 7 - front[t][r];

      next_right[t][r][UP]    = r;
      next_right[t][r][LEFT]  = 7 - t;
      next_right[t][r][RIGHT] = t;
      next_right[t][r][DOWN]  = r;
    }
  }
}

int main(){
  int n;

  initDie();

  while(scanf("%d", &n), n){
    char buff[10];

    int top = 1;
    int right = 3;
    int ans = 1;


    REP(i,n){
      int dir;

      scanf("%s", buff);
      switch(buff[0]){
      case 'N':
	dir = UP;
	break;
      case 'E':
	dir = RIGHT;
	break;
      case 'S':
	dir = DOWN;
	break;
      case 'W':
	dir = LEFT;
	break;
      case 'R':
      case 'L':
	ans += top;
	if(buff[0] == 'R'){
	  right = 7 - front[top][right];
	}else{
	  right = front[top][right];
	}
	continue;
      }

      int ntop  = next_top[top][right][dir];
      int nright = next_right[top][right][dir];

      top = ntop; right = nright;
      ans += top;
    }

    print(ans);
  }

  return 0;
}