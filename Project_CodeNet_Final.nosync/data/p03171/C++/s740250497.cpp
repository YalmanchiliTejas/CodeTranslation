#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;
int A[3001];
long dp[3001][3001];
long solve(int l, int r)
{
    if(l == r)return A[l];
    if(dp[l][r] != -1)return dp[l][r];
    long max_score = 0x8000000000000000;
    max_score = max(max_score, A[l]-solve(l+1, r));
    max_score = max(max_score, A[r]-solve(l, r-1));
    return dp[l][r] = max_score;
}
int main()
{
    int N;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("%ld\n", solve(0, N-1));
    return 0;
}