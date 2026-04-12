#include<bits/stdc++.h>
 #define ll long long int
 ll dp[3010][3030];
using namespace std;
int main()
{
   ll n;
   cin>>n;
   ll a[n];
   for(ll i=0;i<n;i++)
    cin>>a[i];
    for(int i=n-1;i>=0;i--)
        for(int j=i;j<n;j++)
            if(i==j)
                dp[i][j]=a[i];
            else
                dp[i][j]=max((a[i]-dp[i+1][j]),(a[j]-dp[i][j-1]));
    cout<<dp[0][n-1]<<endl;
}