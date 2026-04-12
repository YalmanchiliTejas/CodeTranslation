#include<bits/stdc++.h>
using namespace std;

int N,A[200010];

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",&A[i]);
    for(int i = 0; i < N; i+=2)
    {
        printf("%d ",A[N - i - 1]);
    }
    for(int i = 1; i < N / 2 + 1; i++)
    {
        printf("%d",A[i*2 - 1 - (N%2 == 0)]);
        if(i == N / 2)continue;
        printf(" ");
    }
    printf("\n");
    return 0;
}
