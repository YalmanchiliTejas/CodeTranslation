#include<stdio.h>
#include<algorithm>
using namespace std;
int P[15][15];
main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int A[15];
    for(int i=1;i<=n;i++)
        A[i] = i;

    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        P[a][b] = 1;
        P[b][a] = 1;
    }
    long long counter = 0;
    for(int i=2;i<=n;i++)
        {
            if(!P[A[i]][A[i-1]])
                break;
            if(i == n)
                counter++;
        }
    while(next_permutation(A+2,A+n+1))
    {
        for(int i=2;i<=n;i++)
        {
            if(!P[A[i]][A[i-1]])
                break;
            if(i == n)
                counter++;
        }

    }
    printf("%lld",counter);
}
