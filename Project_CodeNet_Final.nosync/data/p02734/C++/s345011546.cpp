#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll P=998244353;
ll dp[3002][3002],dp2[3002][3002];
int main()
{
    ll t,i,j,k,l,m,n,o,p,q,r,s,a[300002],prefix[300001]={0};
    cin>>n>>s;
    for(i=1;i<=3001;i++)
    {
      for(j=1;j<=3001;j++)
      dp[i][j]=0;
    }
    for(i=1;i<=n;i++)
    {
    cin>>a[i];
    }
    ll ans=0;
    ll res=0;
    ll MOD=998244353;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=s;j++)
        {
                          dp[i][j]+=dp[i-1][j];
            if(j+a[i]<s){
                if(j==0){;
                    dp[i][j+a[i]]+=i;
                    dp[i][j+a[i]]%=MOD;
                }
                else{
                    dp[i][j+a[i]]+=dp[i-1][j];
                    dp[i][j+a[i]]%=MOD;
                }
            }
            else{
                if(j+a[i]==s){
                    if(j==0){
                        res+=(ll)(i)*(n-i+1);
                        res%=MOD;
                    }    
                    else{
                        res+=dp[i-1][j]*(n-i+1);
                        res%=MOD;
                    }
                }
            }
        }
    }
         
          cout<<res<<endl;
    return 0;
}