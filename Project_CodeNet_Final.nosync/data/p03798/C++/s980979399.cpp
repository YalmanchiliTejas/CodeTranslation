#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
char a[100005];
int s[100005];
int N[4][2]= {{0,0},{0,1},{1,1},{1,0}};
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        scanf(" %s",a);
        int f=0;
        for(int k=0; k<4; k++)
        {
            s[0]=N[k][0],s[1]=N[k][1];
            for(int i=1; i<n+1; i++)
            {
                if(!s[i])
                {
                    if(a[(n+i)%n]=='o')
                        s[i+1]=s[i-1];
                    else
                        s[i+1]=s[i-1]^1;
                }
                else
                {
                    if(a[(n+i)%n]=='o')
                        s[i+1]=s[i-1]^1;
                    else
                        s[i+1]=s[i-1];
                }
            }
            if(s[0]==s[n]&&s[1]==s[n+1])
            {
                for(int i=0; i<n; i++)
                    if(!s[i])
                        putchar('S');
                    else
                        putchar('W');
                printf("\n");
                f=1;
                break;
            }
        }
            if(!f)puts("-1");
    }
    return 0;
}
