#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int m =3005;
ll dp[m][m];

int32_t main() 
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j]=a[i];
             else    
                  dp[i][j]=max(a[i]-dp[i+1][j] ,a[j]-dp[i][j-1]);
        }
    }
      cout<<dp[0][n-1];
     return 0;
}
