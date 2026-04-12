#include <bits/stdc++.h>
#define int long long int
#define L_T_S_K ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e6 + 700;
const int mod = 1e9 + 7;
int a , b , k , n;
string lim;
int dp[10005][101][2];

int cntDigit(int n){
  if(!n) return 0;
  return 1 + cntDigit(n / 10);
}

int add(int x , int y){
  return ((x % mod) + (y % mod)) % mod;
}
int sub(int x , int y){
  return ((x % mod) - (y % mod) + mod) % mod;
}
int solve(int i , int mod , int flag){
  if(i == n) {
    if(!mod) return 1 ;
    return 0;
  }
  if(dp[i][mod][flag] != -1) return dp[i][mod][flag] ;
  int ans = 0;
  int limit = 9;
  if(!flag){
    limit = lim[i] - '0';
  }
  for(int j = 0 ; j <= limit ; j++){
    int f1 = flag;
    if(!f1 and j < limit) f1 = 1;
    ans = add(ans ,solve(i + 1 , (mod + j) % k , f1));
  }
  dp[i][mod][flag] = ans;
  return ans;
}
 
int32_t main() {    
 L_T_S_K;
 int t = 1; 
// cin >> t;
 while(t--){
  cin >> lim >> k;
  memset(dp , -1 , sizeof dp);
  n = lim.size();
  int p = solve(0 , 0 , 0);
  cout << sub(p , 1) << "\n"; 
 } 
  return 0;
}