#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int nax = 3005;

ll dp[nax][nax];

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int n;
   cin>>n;
   vector<ll>a(n);
   ll sum = 0;

   for(auto& x : a)cin>>x, sum += x;

   for(int gap = 0; gap < n; gap++){
       for(int i = 0, j = gap; j < n; ++i,++j){
           ll x,y,z;
            x = ((i+2)<=j)?dp[i+2][j] : 0;
            y = ((i+1)<=(j-1))?dp[i+1][j-1] : 0;
            z = ((i <= (j-2)) ? dp[i][j-2] : 0);
           dp[i][j] = max(a[i] + min(x,y), a[j] + min(y,z));
       }
   }

   cout<<2*dp[0][n-1]-sum;




}