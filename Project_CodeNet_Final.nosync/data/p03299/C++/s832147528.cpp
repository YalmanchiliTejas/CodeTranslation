#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

int n;
long long h[111];
long long dp[111][111];
long long MOD=1000000007;

long long hn2h[111];

int hn[111];
map<long long,int>rk;
map<long long,int>::iterator it;
int l;
int m;

long long mul(long long x,long long n)
{
    if(n==0)return 1;
    if(n==1)return x%MOD;
    long long r=mul(x,n/2);
    if(n%2==0)
    {
        return r*r%MOD;
    }
    else
    {
        return r*r%MOD*x%MOD;
    }
}

int main()
{
    int i,j,k;
    int xx;
    long long g,g2;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&h[i]);

        if(rk.find(h[i])==rk.end())
        {
            rk[h[i]]=1;
        }
    }

    m=0;
    hn2h[0]=0;
    for(it=rk.begin();it!=rk.end();it++)
    {
        m++;
        rk[it->first]=m;

        hn2h[m]=it->first;
    }
    for(i=1;i<=n;i++)
    {
        hn[i]=rk[h[i]];

        //cout<<hn[i]<<' ';
    }
    //cout<<"   hn"<<endl;
    hn[0]=0;


    dp[0][0]=1;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=hn[i];j++)
        {
            int nowh=hn[i];
            int nxth=hn[i+1];
            if(j==0)
            {
                dp[i+1][0]=(dp[i+1][0]+dp[i][j]*2ll)%MOD;
                for(k=nowh+1;k<=nxth;k++)
                {
                    g=hn2h[k]-hn2h[k-1];
                    if(k>1)g++;

                    g2=hn2h[nxth]-hn2h[k];

                    dp[i+1][k]=(dp[i+1][k]+dp[i][j]*(mul(2ll,g)-2ll)%MOD*mul(2ll,g2)%MOD)%MOD;
                }
            }
            else
            {
                if(j>nxth)
                {
                    dp[i+1][0]=(dp[i+1][0]+dp[i][j]*2ll)%MOD;
                }
                else
                {
                    if(nxth<=nowh)
                    {
                        dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
                    }
                    else
                    {
                        g=hn2h[nxth]-hn2h[nowh];
                        dp[i+1][j]=(dp[i+1][j]+dp[i][j]*mul(2ll,g)%MOD)%MOD;
                    }
                }
            }
        }
    }

    long long ans=0;
    for(i=0;i<=m;i++)
    {
        ans=(ans+dp[n][i])%MOD;
    }
    ans=(ans+MOD)%MOD;

    cout<<ans<<endl;

/*
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=hn[i];j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
*/
    return 0;
}
