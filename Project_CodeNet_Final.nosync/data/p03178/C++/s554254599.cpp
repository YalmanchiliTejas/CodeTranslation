#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
    string s;
    cin>>s;
    long long int len=s.size();
    long long int d,i,j,k,l;
    cin>>d;

    vector<vector<long long int> > dp(d,vector<long long int> (2,0));
    dp[0][1]=1;

    for(i=0;i<len;i++)
    {
        vector<vector<long long int> > temp_dp(d,vector<long long int> (2,0));
        for(j=0;j<d;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<10;l++)
                {
                    if(k==1&&l>s[i]-'0')
                        break;
                    temp_dp[(j+l)%d][k&&!(l<s[i]-'0')]=(temp_dp[(j+l)%d][k&&!(l<s[i]-'0')]+dp[j][k])%mod;
                }
            }
        }
        dp=temp_dp;
    }

    cout<<(dp[0][0]+dp[0][1]-1+mod)%mod;
}
