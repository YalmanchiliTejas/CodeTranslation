#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define li long long int
#define mod 1000000000+7
li n,k;
li a[3005];
li dp[3005][3005];
li f(li i,li j)
{
   if(i==j)
   {
       return a[i];
   }
   if(i==j-1)
   {
       return max(a[i],a[j]);
   }
   if(dp[i][j]!=-1)
   {
       return dp[i][j];
   }
   li op1=a[i]+min(f(i+2,j),f(i+1,j-1));
   li op2=a[j]+min(f(i+1,j-1),f(i,j-2));
   li ans=max(op1,op2);
   return dp[i][j]=ans;
}

int main()
{
    cin>>n;

    memset(dp,-1,sizeof(dp));
    li i,s=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }

    cout<<2*f(0,n-1)-s;


    return 0;
}
