#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <queue>
#include <list>

using namespace std;
bool ju[10][10];
bool k[10];
int n;
int co=0;
void bfs(int z)
{
    bool f=true;
    for(int i=2;i<=n;++i)
    {
        if(k[i]==false&&ju[z][i])
        {
            f=false;
            k[i]=true;
            bfs(i);
            k[i]=false;
        }
    }
    if(f)
    {
        bool ff=true;
        for(int i=2;i<=n;++i)
            if(k[i]==false)
        {
            ff=false;
            break;
        }
        if(ff) ++co;
    }
}
int main()
{
    int m,a,b;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        ju[a][b]=ju[b][a]=true;
    }
    k[1]=true;
    bfs(1);
    printf("%d",co);
    return 0;
}
