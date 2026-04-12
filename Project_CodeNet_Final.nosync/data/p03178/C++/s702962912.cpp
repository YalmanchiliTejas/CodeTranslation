#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define maxn 100000
using namespace std;

ll dp[2][102][2],d,len;
char str[10123];

void add_self(ll &a,ll b)
{
    a+=b;
    if(a>=mod)
    {
        a-=mod;
    }
}

int main()
{
    cin>>str;
    cin>>d;
    len = strlen(str);
    dp[0][0][0] = 1;
    int fl = 0;
    for(int where=0;where<len;where++)
    {
        fl^=1;
        for(int sum=0;sum<d;sum++)
        {
            for(int isSmaller =0;isSmaller<2;isSmaller++)
            {
                for(int digits=0;digits<10;digits++)
                {
                    if(digits> str[where]-'0' && isSmaller == 0)
                    {
                        break;
                    }
                    add_self(dp[fl][(sum+digits)%d][isSmaller || (digits < str[where]-'0') ],dp[fl^1][sum][isSmaller]);
                }
            }
        }
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<2;j++) dp[fl^1][i][j] = 0;
        }
    }

    ll ans = (dp[fl][0][1]+dp[fl][0][0])%mod;
    --ans;
    if(ans == -1) {
        ans = mod-1;
    }
    cout<<ans<<endl;
}
