#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long mod = 1000000007;



 
const int mx = 3005;

ll dp[mx][mx];

int main(){
   int n;

   cin>>n;

   int a[n];

   int i,j , k;

   for(i = 0 ;i < n;i++)
    cin>>a[i];

   for(int l = n-1;l >= 0;l--){
       for(int r = l;r  < n;r++){
           if(l == r)
            dp[l][r] = a[l];
           else{
               dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
           } 
       }
   }
   cout<<dp[0][n-1];
} 
