#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<climits>
#define MOD 1000000007
typedef long long ll;
using namespace std;

string n;
int k;
ll dp[105][2][5];

int main(){
  cin >> n >> k;
  int nsize = (int)n.size();

  dp[0][0][0] = 1;

  for(int i=0;i<nsize;i++){
    for(int isless=0;isless<2;isless++){
      for(int j=0;j<=k;j++){
        int c = n[i] - '0';
        for(int num=0;num<=9;num++){
          
          if(c < num && isless == 0) continue;

          int isless_next = isless;
          if(num < c) isless_next = 1;

          int j_next = j;
          if(num != 0) j_next++;

          dp[i+1][isless_next][j_next] += dp[i][isless][j];

        }
      }
    }
  }

  cout << dp[nsize][0][k] + dp[nsize][1][k] << endl;
  return 0;
}