#include<stdio.h>
#include<memory.h>
#include<algorithm>

using namespace std;
long dp[3001][3001];
int A[3001];
int main()
{
    int N;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    int x;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
        dp[i][i] = A[i];
        for(int j=i-1; j>=0; j--)
        {
            dp[j][i] = max((A[j]-dp[j+1][i]), (A[i]-dp[j][i-1]));
        }
    }
    printf("%ld\n", dp[0][N-1]);
    return 0;
}