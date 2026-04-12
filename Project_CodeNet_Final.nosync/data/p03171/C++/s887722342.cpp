#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <cstring>

#define ll long long
using namespace std; 
long a[3001];

void solve(){
  int n; 
  cin >> n; 
  // vector<int> a(n); 
  for(int i=0; i<n; i++){
    cin >> a[i]; 
  }
  long dp[n][n]; 
  for(int l=1; l<=n; l++){
    for(int i=0; i<=n-l; i++){
      if(l==1){
        dp[i][i] = a[i];  
      }else{
        dp[i][i+l-1] = max(a[i]- dp[i+1][i+l-1], a[i+l-1] - dp[i][i+l-2]); 
      }
    }
  }
  cout << dp[0][n-1] << "\n"; 
}

int main(){
  int t=1; 
  // cin>>t; 
  while(t--){
    solve(); 
  }
 return 0;
}