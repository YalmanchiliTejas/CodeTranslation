#include<iostream>
#include<cmath>
#include<unordered_map>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
#define PI 3.14159265
#define mod 998244353  
#define mod1 1e9 + 7  
using namespace std;

void func(){
   int n ;
   cin >> n ; 
   long long arr[n + 1], dp[n + 1][n + 1];

   for(int i = 0 ; i < n ; ++i){
       cin >> arr[i + 1];
   }

   for(int i = 1 ; i <= n ; ++i){
       dp[i][i] = arr[i];
   } 

   for(int i = 1 ; i <= n ; ++i){
       int cnt = 1;
       for(int j = i + 1 ; j <= n ; ++j ){
           dp[cnt][j] = max(arr[cnt] - dp[cnt + 1][j], arr[j] - dp[cnt][j - 1]);
           ++cnt;
       }
   }

cout << dp[1][n];
}

int main(){
    int t = 1 , cnt = 0 ;
  //  cin >> t;
    
    while(t--){  
        func();
    }
}