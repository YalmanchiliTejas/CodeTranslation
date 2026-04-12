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
#include<complex>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef complex<double> P;

#define MAX 1010

int main(){
  int n;
  while(scanf("%d",&n),n){
    int ans[n][n];
    int x = n/2, y = n/2 + 1;
    memset(ans, 0, sizeof(ans));
    REP(i,n*n){
      ans[y][x] = i + 1;

      x++; y++;
      x = (x + n) % n;
      y = (y + n) % n;
      if(i != n*n-1)
      while(ans[y][x] != 0){
	x--; y++;
	x = (x + n) % n;
	y = (y + n) % n;
      }
    }
    REP(i, n){ 
      REP(j, n)
	printf("%4d",ans[i][j]);
      puts("");
    }
  }
  return 0;
}