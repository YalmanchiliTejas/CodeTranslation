#include <algorithm>
#include <queue>
#include <cstdio>
typedef long long LL ;
using namespace std ;
int main()
{
    int X,Y,Z;
    while(scanf("%d %d %d",&X,&Y,&Z)!=EOF)
    {
        int sum;
        sum=X-Z;
        printf("%d\n",sum/(Y+Z));
    }
    return 0;
}
