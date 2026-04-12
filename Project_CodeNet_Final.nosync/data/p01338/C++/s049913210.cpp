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
#include<complex>

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
#define EPS (1e-4)

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

int dp[4][256];
int board[5][5];

int ten[4] = { 0,60,70,80 };

#define H(h,x) ((h>>(x+x)) & 3)

int solve(int now, int h){
  if(dp[now][h] != -1) return dp[now][h];
  int ret = 0;

  int tmp[5] = {0};
  if(board[now][0] != 0) tmp[0] = 1 + ((board[now][0] - 1) + H(h,0)) % 4;
  if(board[now][1] != 0) tmp[1] = 1 + ((board[now][1] - 1) + H(h,0) + H(h,1)) % 4;
  if(board[now][2] != 0) tmp[2] = 1 + ((board[now][2] - 1) + H(h,1) + H(h,2)) % 4;
  if(board[now][3] != 0) tmp[3] = 1 + ((board[now][3] - 1) + H(h,2) + H(h,3)) % 4;
  if(board[now][4] != 0) tmp[4] = 1 + ((board[now][4] - 1) + H(h,3)) % 4;

  REP(x,256){
    int rtmp = 0;
    if(tmp[0] != 0) rtmp += ten[((tmp[0] - 1) + H(x,0)) % 4];
    if(tmp[1] != 0) rtmp += ten[((tmp[1] - 1) + H(x,0) + H(x,1)) % 4];
    if(tmp[2] != 0) rtmp += ten[((tmp[2] - 1) + H(x,1) + H(x,2)) % 4];
    if(tmp[3] != 0) rtmp += ten[((tmp[3] - 1) + H(x,2) + H(x,3)) % 4];
    if(tmp[4] != 0) rtmp += ten[((tmp[4] - 1) + H(x,3)) % 4];

    if(now == 3){
      if(board[4][0] != 0)
        rtmp += ten[((board[4][0] - 1) + H(x,0)) % 4];
      if(board[4][1] != 0)
        rtmp += ten[((board[4][1] - 1) + H(x,0) + H(x,1)) % 4];
      if(board[4][2] != 0)
        rtmp += ten[((board[4][2] - 1) + H(x,1) + H(x,2)) % 4];
      if(board[4][3] != 0)
        rtmp += ten[((board[4][3] - 1) + H(x,2) + H(x,3)) % 4];
      if(board[4][4] != 0)
        rtmp += ten[((board[4][4] - 1) + H(x,3)) % 4];
      ret = max(ret, rtmp);
    }else{
      ret = max(ret, rtmp + solve(now+1,x));
    }
  }
  return dp[now][h] = ret;
}

int main(){
  int n = getInt();
  while(n --> 0){
    memset(dp, -1, sizeof(dp));
    REP(i,5) REP(j,5) board[i][j] = getInt();
    print(solve(0,0));
  }
  return 0;
}