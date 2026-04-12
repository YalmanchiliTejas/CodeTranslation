#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define MOD 998244353
#define MAX 3005
#define MAX_W 1001
int A[MAX];
long long int dp[MAX][MAX][2][2];
int N,S;
void initialize(int N,int S)
{
    int i,j,k,l;
    for(i=0;i<=N;i++)
    {
        for(j=0;j<=S;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<2;l++)
                {
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
}
long long int counter(int index,int sum,int b=0,int e=0)
{
    if(index==N) return (sum==0);
    if(dp[index][sum][b][e]!=-1)
    {
        return dp[index][sum][b][e];
    }
    dp[index][sum][b][e]=counter(index+1,sum,b,e)%MOD;
    if(A[index]<=sum)
    {
        long long int current=1;
        if(b==0) current=(current*(index+1))%MOD;
        if(A[index]==sum) current=(current*(N-index))%MOD;
        current=(current*counter(index+1,sum-A[index],1,(sum-A[index]==0)))%MOD;
        dp[index][sum][b][e]=(dp[index][sum][b][e]+current)%MOD;
    }
    return dp[index][sum][b][e];
}
int main()
{
    int i;
    scanf("%d %d",&N,&S);
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    initialize(N,S);
    long long int ans=counter(0,S);
    printf("%lld",ans);
    return 0;
}
