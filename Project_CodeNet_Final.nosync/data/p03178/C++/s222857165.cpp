#include <iostream>
#define NMAX 100005
#define DMAX 105
using namespace std;
string k;
int d;
int dp[NMAX][DMAX][2];
const int MOD=1e9+7;
int main()
{
    cin>>k;
    cin>>d;
    dp[0][0][0]=1;
    for(int i=1;i<=(int)k.size();i++)
    {
        for(int sum=0;sum<d;sum++)
        {
            for(int digit=0;digit<=(k[i-1]-'0');digit++)
            {
                dp[i][(sum+digit)%d][0 || (digit<k[i-1]-'0')]+=dp[i-1][sum][0];
                dp[i][(sum+digit)%d][0 || (digit<k[i-1]-'0')]%=MOD;
            }
            for(int digit=0;digit<=9;digit++)
            {
                dp[i][(sum+digit)%d][1]+=dp[i-1][sum][1];
                dp[i][(sum+digit)%d][1]%=MOD;
            }
        }
    }
    int sz=k.size();
    int sol=(dp[sz][0][0]+dp[sz][0][1])%MOD;
    sol=(MOD+sol-1)%MOD;
    cout<<sol;
    return 0;
}
