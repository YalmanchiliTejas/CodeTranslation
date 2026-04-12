#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll dp[3234][3234], step[3124][3123];
vector <ll> vec;

ll solve(int l, int r){
    int cnt = vec.size()-1 - (r-l+1);
    //cout << l << "|" << r << " " << cur << endl;
   if(dp[l][r] != -1){
       return dp[l][r];
   }
   if(l == r){
      if(cnt%2 == 0) 
      return vec[l];
      else 
      return -1LL*vec[l];
   }
   ll x, y;
   if(cnt % 2 == 0){
      
       x = solve(l+1, r);
       y = solve(l, r-1);
   } else{
       x = solve(l+1, r);
       y = solve(l, r-1);
   }
   //cout << l << "|" << r << "|" << x << "|" << y << endl;
   if(cnt%2 == 0){
       if(vec[l]+x > vec[r]+y){
           dp[l][r] = vec[l]+x;
       } else{
           dp[l][r] = vec[r]+y;
       }
      
   }else{
       if(-1LL*vec[l]+x < -1LL*vec[r]+y){
           dp[l][r] = -1LL*vec[l]+x;
       } else{
           dp[l][r] = -1LL*vec[r]+y;
       }
   }
   //cout << dp[l][r] << endl;
   return dp[l][r];
}

int main()
{
   ll n;
   cin >> n;
   vec.resize(n+1);

   for(int i = 1; i <= n; i++){
       cin >> vec[i];
   }
   for(int i = 1; i <= n; i++){
       for(int j = 1; j <= n; j++) dp[i][j] = -1;
   }

   cout << solve(1, n);
   
}
