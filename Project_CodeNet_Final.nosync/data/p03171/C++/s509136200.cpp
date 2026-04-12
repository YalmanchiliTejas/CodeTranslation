#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int n;
  cin>>n;
  ll arr[n];
  ll sum=0;
  for(int i=0;i<n;i++)
  {cin>>arr[i];
   sum+=arr[i];
  }
  ll table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            ll x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            ll y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            ll z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
  
    cout<<2*table[0][n - 1]-sum; 
}