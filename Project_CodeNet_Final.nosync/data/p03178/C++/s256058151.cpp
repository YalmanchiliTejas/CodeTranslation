#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define MOD 1000000007
#define MAX_N 10004
#define f first 
#define s second 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll inf=1e18;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll dig_dp[MAX_N][100];
    l x=0,d,y;
    string num;
    cin>>num;
    cin>>d;
    for(l i=0;i<MAX_N;i++)
    {
        for(l j=0;j<100;j++)
        {
            dig_dp[i][j]=0;
        }
    }
    for(l i=0;i<MAX_N;i++)
    {
        for(l j=0;j<d;j++)
        {
            if(i==0)
            {
                for(l dig=0;dig<10;dig++)
                {
                    if((dig-j)%d==0)
                        dig_dp[i][j]++;
                }
            }
            else 
            {
                for(l dig=0;dig<10;dig++)
                {
                    x=(j-dig)%d;
                    if(x<0)
                        x+=d;
                    dig_dp[i][j]=(dig_dp[i][j]+dig_dp[i-1][x])%MOD;
                }
            }
        }
    }
    x=0;
    ll ans=0;
    reverse(num.begin(),num.end());
    for(l i=num.size()-1;i>=0;i--)
    {
        for(l j=0;j<num[i]-'0';j++)
        {
            y=(d-x-j)%d;
            if(y<0)
                y+=d;
            if(i>0)
                ans=(ans+dig_dp[i-1][y])%MOD;
            else if(y==0)
                ans=(ans+1)%MOD;
        }
        x=(x+num[i]-'0')%d;
        if(x<0)
            x+=d;
    }
    if(x!=0)
        ans=(ans-1)%MOD;
    if(ans<0)
        ans+=MOD;
    cout<<ans<<endl;
}