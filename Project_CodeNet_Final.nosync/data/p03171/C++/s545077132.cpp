#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int n;
vector<long long> a;
long long dp[3010][3010];
int main(){
 cin >> n;
 a.resize(n);
 for(int i = 0; i < n; ++i)cin >> a[i];
 for(int len = 1; len <= n; ++len){
   for(int i = 0; i+ len <= n; ++i){
     int j = i + len;
     if((n - len) %2 == 0){
       dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
     }else{
       dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
     }
   }
 }
 cout << dp[0][n] << endl;
 return 0;
}