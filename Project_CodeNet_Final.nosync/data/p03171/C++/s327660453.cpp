#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e3+5 , inf = 0x3f3f3f3f3f3f3f3f;
int n , dp[N][N][2] , A[N];

int rec(int x , int y , int cnt){
  if(dp[x][y][cnt] != inf) return dp[x][y][cnt];
  if(cnt == 1){
    return dp[x][y][1] = max(rec(x+1,y,0)+A[x],rec(x,y-1,0)+A[y]);
  }
  else{
    return dp[x][y][0] = min(rec(x+1,y,1)-A[x],rec(x,y-1,1)-A[y]);
  }
}

main(){
  cin >> n;
  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < N ; j++) 
      for(int z = 0 ; z <= 1 ; z++) dp[i][j][z] = inf;
  for(int i = 1 ; i <= n ; i++){
    cin >> A[i];
    dp[i][i][1] = A[i] ,  dp[i][i][0] = -dp[i][i][1];
  }
  rec(1,n,1);
  cout << dp[1][n][1] << "\n";
}
