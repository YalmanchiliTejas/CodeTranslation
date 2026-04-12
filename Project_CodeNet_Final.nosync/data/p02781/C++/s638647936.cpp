#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=205;
int p,n;
char s[N];
ll dp[N][4][2];
int main()
{
    scanf("%s",s+1);
    scanf("%d",&p);
    int n=strlen(s+1);
    dp[0][0][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=3;j++)
            for(int k=0;k<=1;k++)
        {
            int up=k?s[i]-'0':9;
            if(j==p) up=0;
            for(int h=0;h<=up;h++)
                dp[i][j+(h!=0)][k&&(h==up)]+=dp[i-1][j][k];
        }
    printf("%lld\n",dp[n][p][0]+dp[n][p][1]);
}
