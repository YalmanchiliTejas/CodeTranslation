#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define N 3003

typedef long long ll;

int n, a[N];
ll dp[N][N][3];

//0->taro, 1->jiro
ll dif(int l, int r, int p){
  if(l+r==n) return 0;
  if(dp[l][r][p]!=-1) return dp[l][r][p];
  if(p) return dp[l][r][p]=min((ll) dif(l+1, r, p^1)-a[1+l], (ll) dif(l, r+1, p^1)-a[n-r]);
  return dp[l][r][p]=max((ll) dif(l+1, r, p^1)+a[1+l], (ll) dif(l, r+1, p^1)+a[n-r]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) cin >> a[i];

  for(int i=0; i<=n+1; i++){
    for(int j=0; j<=n+1; j++){
      for(int k=0; k<=2; k++){
        dp[i][j][k]=-1;
      }
    }
  }

  cout << dif(0, 0, 0) << endl;
}
