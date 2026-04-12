#include <cstdio>
#include <algorithm>
using namespace std;

int n,h,m,ans;

int main()
{
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&h);
        if (h>=m)
        {
            m=h;
            ans++;
        }
    }
    printf("%d",ans);
    getchar(); getchar();
    return 0;
}