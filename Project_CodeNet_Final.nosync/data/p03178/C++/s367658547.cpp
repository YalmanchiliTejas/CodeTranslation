#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int MOD=1000000007;
const int nmax=3123;

int d,a,b,i2,kmax,pos;
ll dp[102],res,tmp[102],tmp2;
char k[10002];

int main()
{
    scanf("%s",&k);
    for(; k[kmax]!=0; ++kmax)
    {
        a+=k[kmax]-'0';
    }
    scanf("%d",&d);
    pos=kmax-1;
    dp[0]=1;
    a%=d;
    if(a==0)
        ++res;
    while(pos>=0)
    {
        if(k[pos]!='0')
        {
            b=k[pos]-'0';
            a-=b;
            while(a<0)
                a+=d;
            tmp2=0;
            i2=(d-a)%d;
            for(int i=0; i<b; ++i)
            {
                tmp2+=dp[i2];
                --i2;
                if(i2<0)
                    i2+=d;
            }
            res=(res+tmp2)%MOD;
        }
        tmp[0]=0;
        i2=d-1;
        for(int i=0; i<9; ++i)
        {
            tmp[0]+=dp[i2];
            --i2;
            if(i2<0)
                i2+=d;
        }
        for(int i=1; i<d; ++i)
        {
            ++i2;
            i2%=d;
            tmp[i]=tmp[i-1]+dp[i-1]-dp[i2];
        }
        for(int i=0; i<d; ++i)
        {
            dp[i]=(dp[i]+tmp[i])%MOD;
        }
        --pos;
    }
    --res;
    if(res<0)
        res+=MOD;
    printf("%lld",res);
    return 0;
}
