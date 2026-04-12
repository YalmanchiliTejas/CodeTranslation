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
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;
static const long long INF = 1<<31;

string s;
int n, dp[100005][4];

int main(void) {
  cin >> n >> s;
  
  for (int i=0; i<=1; i++) for (int j=0; j<=3; j++) dp[i][j] = (j>>i) & 1;
  
  for (int i=1; i<n-1; i++) for (int j=0; j<=3; j++) {
    dp[i+1][j] = (dp[i-1][j] + dp[i][j] + (s[i]=='o' ? 1 : 0) ) % 2;
  }
  
  int idx = -1;
  for (int i=0; i<=3; i++) {
    if (((dp[n-2][i]+dp[n-1][i]+(s[n-1]=='o' ? 1 : 0))%2 == dp[0][i]) && (dp[0][i]+dp[1][i]+(s[0]=='o' ? 1 : 0))%2==dp[n-1][i]) idx = i;
  }
  
  if (idx==-1) {
    puts("-1");
    return 0;
  }
  
  for (int i=0; i<n; i++) {
    if (dp[i][idx]) printf("S");
    else printf("W");
  }
  
  printf("\n");
  
    
    //cout << ans << "\n";

    return 0;
}

