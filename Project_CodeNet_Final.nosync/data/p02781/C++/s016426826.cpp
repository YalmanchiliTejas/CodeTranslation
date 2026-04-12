#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][4]={0};
int main()
{
    int k;
    string s;
    cin>>s>>k;
    int n=s.size();
    ll ans=0;
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    for(int i=1;i<=n;i++)
        dp[i][1]=9*i;
    for(int j=2;j<=3;j++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int kk=1;kk<i;kk++)
                dp[i][j]+=9*dp[kk][j-1];
        }
    }
    if(n<k)
    {
        cout<<"0\n";
        return 0;
    }
    if(k==1)
    {
        cout<<dp[n-1][1]+(s[0]-'0');
        return 0;
    }
    if(k==2)
    {
        int a1=1;
        while(s[a1]=='0') a1++;
        if(a1==n) cout<<dp[n-1][2]+(s[0]-'0'-1)*dp[n-1][1];
        else cout<<dp[n-1][2]+(s[0]-'0'-1)*dp[n-1][1]+dp[n-a1-1][1]+(s[a1]-'0');

    }
    if(k==3)
    {
        int a1=1;
        while(s[a1]=='0') a1++;
        if(a1==n)
        {
            cout<<dp[n-1][3]+(s[0]-'0'-1)*dp[n-1][2];
            return 0;
        }
        int a2=a1+1;
        while(s[a2]=='0') a2++;
        if(a2==n)
        {
            cout<<dp[n-1][3]+(s[0]-'0'-1)*dp[n-1][2]+dp[n-a1-1][2]+(s[a1]-'0'-1)*dp[n-a1-1][1];
            return 0;
        }
        else cout<<dp[n-1][3]+(s[0]-'0'-1)*dp[n-1][2]+dp[n-a1-1][2]+(s[a1]-'0'-1)*dp[n-a1-1][1]+dp[n-a1-a2][1]+(s[a2]-'0');
    }
}
