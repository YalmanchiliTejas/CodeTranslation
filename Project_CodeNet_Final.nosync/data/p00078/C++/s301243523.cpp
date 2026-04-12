#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 15

int jin[MAX][MAX];
int main()
{

    int n;
    while(cin>>n)
    {
        if(n==0)break;
        memset(jin,0,sizeof(jin));
        int x = n/2, y = n/2 +1;
        int nextx,nexty;
        jin[x][y] = 1;
        for(int i=2;i<=n*n;++i)
        {
            nextx = (x==(n-1) )? 0:x+1;
            nexty =(y==n-1)? 0 : y+1;
            if(jin[nextx][nexty] == 0)
            {
                jin[nextx][nexty] = i;
                x = nextx; y = nexty;
            }
            else
            {
                nextx = (nextx==(0))? n-1:nextx-1;
                nexty = (nexty==n-1)? 0:nexty+1;
                jin[x][nexty] = i;
                x = nextx;
                y = nexty;
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                printf("%4d",jin[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}