#include<bits/stdc++.h>
using namespace std;
#define int long long 

int dp[3010];
// kmjp参照
const int MOD = 998244353;

void modadd(int &a, int b){ 
  a = (a+b)%MOD;
}

signed main(void){
  
  int n,S; cin >> n >> S;
  
  int ans =0 ;
  
  for(int i = 0; i < n; i++){ 
    int x; cin >> x;
    for(int j = S-x; j >= 0; j--){ 
      if( j != 0 ){ 
        modadd(dp[j+x],dp[j]);
      }
      else{ 
        modadd(dp[x],i+1);
      }
    }
    
    modadd(ans,dp[S]);
  }
  
  cout << ans << endl;
  
  return 0;
}