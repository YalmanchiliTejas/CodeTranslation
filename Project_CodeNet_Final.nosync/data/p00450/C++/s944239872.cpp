#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int N, c[100000], C;

int main(){
  while(scanf("%d", &N) && N){
    memset(c, 0, sizeof(c));
    scanf("%d", &C);
    int index = 0, left, prev ;
    c[index] =  1;
    left = prev =  C;
    REP(i, 2, N+1){
      scanf("%d", &C);
      if(C == prev){
	c[index]++;
      }else if(i%2 == 0){
	if(index == 0){
	  c[index]++;
	  left = C;
	}else{
	  c[index-1] += c[index] + 1;
	  index--;
	}
      }else{
	index++;
	c[index] = 1;
      }
      prev = C;
    }
    int res = 0;
    rep(i, index+1){
      if((i+left)%2 == 0) res += c[i];
      //      printf("%d\n", c[i]);
    }
    printf("%d\n", res);
  }
  return 0;
}