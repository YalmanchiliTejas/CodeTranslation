#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pa pair<int,int>
#define ld long double
#define BOOST ios_base::sync_with_stdio(false)
#define pb push_back
#define st first
#define nd second
using namespace std;
const int mod=1e9+7;
const int MAX=105;
ll dp[MAX][2];
int main()
{
    BOOST;
    string maximum;
    cin>>maximum;
    int dzielnik;
    cin>>dzielnik;
    dp[0][0]=1;
    int len=maximum.size();
    for (int where=0;where<len;where++)
    {
        ll new_dp[MAX][2];
        for (int i=0;i<MAX-1;i++)
        {
            for (int j=0;j<2;j++)
            {
                new_dp[i][j]=0;
            }
        }

        for (int sum=0;sum<dzielnik;sum++)
        {
            for (int i=0;i<2;i++)
            {
                for (int digit=0;digit<10;digit++)
                {
                    if (digit>maximum[where]-'0' && !i)
                    {
                        break;
                    }

                    new_dp[(sum+digit)%dzielnik][i || (digit<maximum[where]-'0')]=
                    (new_dp[(sum+digit)%dzielnik][i || (digit<maximum[where]-'0')]+
                    dp[sum][i])%mod;
                }
            }
        }

        for (int i=0;i<MAX-1;i++)
        {
            for (int j=0;j<2;j++)
            {
                dp[i][j]=new_dp[i][j];
            }
        }
    }
    cout<<(dp[0][0]+dp[0][1]-1+mod)%mod;
    return 0;
}
