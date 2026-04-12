#include <iostream>
typedef long long ll;
using namespace std;

ll dp[3005][3005];
ll a[3005];
int n;
const ll INF = -1e14;
ll rec(int i, int j, bool AorB) {
  if(i > j) return 0;
  if(dp[i][j] > INF) return dp[i][j];
 
  ll res;
  if(AorB) {
    res = max(rec(i+1,j,false) + a[i], rec(i,j-1,false) + a[j]);
  }
  else {
    res = min(rec(i+1,j,true) - a[i], rec(i,j-1,true) - a[j]);
  }
  //cout << i <<"   "<< j << endl;
  //cout << res << endl;
 return dp[i][j] = res;
}


int main() {
  cin >> n;

  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = INF;
    }
  }
  cout << rec(0,n-1,true) << endl;
}
