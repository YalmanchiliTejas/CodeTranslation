#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans;
string s, N = "x";
int K;
ll dp[105][4][2];

int main(void) {
    cin >> s;
    N += s;
    
    scanf("%d", &K);
    int sz = (int)N.size();
    dp[0][0][0] = 1;
    for(int i=1; i<=sz-1; i++) for(int j=0; j<=K; j++) for(int k=0; k<=1; k++) {
      int u = k ? 9 : N[i] - '0';
      if (j == K) u = 0;
      for (int l = 0; l<=u; l++){
        dp[i][j+(l!=0)][(k || l<u)] += dp[i-1][j][k];
      }
    
    } 

    printf("%lld\n", dp[sz-1][K][0]+dp[sz-1][K][1]);

    return 0;
}

