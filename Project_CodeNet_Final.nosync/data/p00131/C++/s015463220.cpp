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

const int mask = (1<<10)-1;

int main(){
  int n;
  scanf("%d",&n);
  while(n --> 0){
    int data[10] = { 0 };
    REP(i,10) REP(j,10){
      int tmp; scanf("%d",&tmp);
      if(tmp == 1) data[i] |= (1 << j);
    }

    REP(k,(1<<10)){
      int d[10]; REP(i,10) d[i] = data[i];
      d[0] ^= k; d[0] ^= (k<<1); d[0] ^= (k>>1);
      d[1] ^= k;

      int ans[10] = { k };
      for(int i=0; i<9; i++){
        int tmp = 0;
        REP(j,10){
          if(d[i] & (1<<j)){
            tmp |= (1<<j);
          }
        }
        d[i] ^= tmp;
        d[i+1] ^= tmp; d[i+1] ^= (tmp<<1); d[i+1] ^= (tmp>>1);
        if(i!=8) d[i+2] ^= tmp;
        ans[i+1] = tmp;
      }
      if((d[9] & mask) == 0){
        REP(i,10) REP(j,10)
          printf("%d%c",((ans[i]&(1<<j))==0?0:1),(j==9?'\n':' '));
        break;
      }
    }
  }

  return 0;
}