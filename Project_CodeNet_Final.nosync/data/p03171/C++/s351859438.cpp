#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    int a[3001];
    long long int dp[3001][3001];
    long long int s=0;
   for(int i=0;i<n;i++){cin>>a[i];s=s+a[i];
       for(int j=0;j<n;j++)dp[i][j]=0;
   }
   for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
            long long int x = ((i + 2) <= j) ? dp[i + 2][j] : 0; 
            long long int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0; 
            long long int z = (i <= (j - 2)) ? dp[i][j - 2] : 0; 
  
            dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z)); 
        } 
    } 
  // lol(0,n-1);
   long long int ans=dp[0][n-1];
   cout<<2*ans-s<<endl;
}