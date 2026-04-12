/*g++ file.cpp -o file.out*/
/*./file.out*/

#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define Mod 1000000007
#define L_Mod 17100000013

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))

int s[11][11]= {0};
int visit[11]= {0};
int n,m,a,b,sov=0,sum=0;

void dfs(int x,int dot)
{
    if(dot==n)
    {
        sum++;
        return;
    }
    rep(i,n+1)if(s[x][i]==1&&visit[i]!=1)
    {
        visit[i]=1;
        dfs(i,dot+1);
        visit[i]=0;
    }
    return;
}

int main()
{
    scanf("%d%d",&n,&m);
    rer(i,1,m)
    {
        scanf("%d%d",&a,&b);
        s[a][b]=1;
        s[b][a]=1;
    }
    visit[1]=1;
    dfs(1,1);
    printf("%d\n",sum);
    return 0;
}
