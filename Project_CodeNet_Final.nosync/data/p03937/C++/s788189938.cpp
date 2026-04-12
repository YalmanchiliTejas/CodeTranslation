#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char str[25][25];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(str[i][j]=='#'&&str[i+1][j]=='#'&&str[i][j+1]=='#')
            {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(str[i][j]=='#'&&str[i-1][j]=='#'&&str[i][j-1]=='#')
            {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    printf("Possible\n");
}