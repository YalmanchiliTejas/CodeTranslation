#include<bits/stdc++.h>
using namespace std;

#define se second
#define fi first
#define mk(a,b) make_pair(a,b)

typedef pair<int,int> pii;

int A,B;
int D[11][11];
int mem[110][110];
vector<pii> G[300];
int dis[300];

int main()
{
    scanf("%d%d",&A,&B);
    for(int i = 1; i <= A; i++)
    {
        for(int j = 1; j <= B; j++)
        {
            scanf("%d",&D[i][j]);
        }
    }

    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            int res = 0;
            for(int k = 1; k <= A; k++)
            {
                for(int l = 1; l <= B; l++)
                {
                    res = max(res,D[k][l] - i * k - j * l);
                }
            }
            if(res > 100)
            {
                printf("Impossible\n");
                return 0;
            }
            mem[i][j] = res;
        }
    }

    for(int i = 1; i <= A; i++)
    {
        for(int j = 1; j <= B; j++)
        {
            int MIN = 1001001001;
            for(int k = 0; k <= 100; k++)
            {
                for(int l = 0; l <= 100; l++)
                {
                    MIN = min(MIN,k * i + l * j + mem[k][l]);
                }
            }
            if(MIN != D[i][j])
            {
                printf("Impossible\n");
                return 0;
            }
        }
    }

    printf("Possible\n");

    printf("202 10401\n");
    for(int i = 0; i < 100; i++)
    {
        printf("%d %d X\n",i + 1,i + 2);
        printf("%d %d Y\n",i + 2 + 101,i + 1 + 101);
    }

    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            printf("%d %d %d\n",i + 1,j + 1 + 101,mem[i][j]);
        }
    }

    printf("1 102\n");

    return 0;
}
