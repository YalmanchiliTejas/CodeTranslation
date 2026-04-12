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

struct stones{
  int col;
  int num;
  struct stones *next;
};

int main(){
  int n;
  while(n = getInt()){
    stones *st = NULL;
    REP(i,n){
      int col = getInt();
      if(i % 2 == 0 || st->col == col){
	if(st == NULL || st->col != col){
	  stones *tmp = (stones *)malloc(sizeof(stones));
	  tmp->col = col;
	  tmp->num = 1;
	  tmp->next = st;
	  st = tmp;
	}else{
	  st->num++;
	}
      }else{
	stones *tmp = st;
	st = tmp->next;
	if(st == NULL){
	  st = tmp;
	  st->col = col;
	  st->num++;
	}else{
	  st->num += 1 + tmp->num;
	  free(tmp);
	}
      }

      /*
      {
	stones *tmp = st;
	while(tmp != NULL){
	  REP(i, tmp->num){
	    putchar(tmp->col == 0 ? 'W' : 'B');
	  }
	    putchar(' ');
	  tmp = tmp->next;
	}
	puts("");
      }
      */
    }
    int ans = 0;
    while(st != NULL){
      stones *tmp = st;
      if(st->col == 0)
	ans += st->num;
      st = tmp->next;
      free(tmp);
    }

    print(ans);
  }

  return 0;
}