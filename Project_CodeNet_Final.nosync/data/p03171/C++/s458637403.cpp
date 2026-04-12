#include <bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vs vector<string>
#define mii map<long long int, long long int>

void show(auto a){
  long long int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}



long long int dp[3005][3005];


int main(){
  ios_base::sync_with_stdio(false);

  long long int n; cin>>n;
  vi a(n); for(long long int i = 0; i < n; i++) cin>>a[i];

  for(long long int i = 0; i <= 3004; i++){
  	for(long long int j = 0; j <= 3004; j++){
  		dp[i][j] = 0;
  	}

  }
  //dp[l][r] = max value of X-Y for long long interval l, r

  for(long long int l = n-1; l >= 0; l--){
  	for(long long int r = 0; r < n; r++){
  		if(l == r) dp[l][r] = a[l];
  		else dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
  	}
  }

  cout<<dp[0][n-1]<<endl;


}