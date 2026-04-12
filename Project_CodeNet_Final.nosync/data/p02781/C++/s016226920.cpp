#include<bits/stdc++.h>
#define ll long long
const int maxn=1e2+10;
using namespace std;

ll dp[maxn][maxn][2];
int main()
{
    string s;
    int K;
    cin>>s;
    cin>>K;
    int len=s.length();
    dp[0][0][0]=1;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<2;k++)
            {
                int numd=s[i]-'0';
                for(int l=0;l<10;l++)
                {
                    int numi=i+1,numj=j,numk=k;
                    if(l!=0) numj++;
                    if(numj>K) continue;
                    if(k==0)
                    {
                        if(l>numd) continue;
                        if(l<numd) numk=1;
                    }
                    dp[numi][numj][numk]+=dp[i][j][k];

                }
            }
        }
    }
    ll ans=dp[len][K][0]+dp[len][K][1];
    cout<<ans<<endl;
    return 0;
}