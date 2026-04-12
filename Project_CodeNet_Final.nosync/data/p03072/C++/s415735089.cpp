#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,n,i,j,k;
int str[25];
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&str[i]);
        }
        b=str[0];c=0;
        for(i=0;i<n;i++)
        {
            if(str[i]>=b)
                c++;
            if(str[i]>b)
                b=str[i];
        }
        printf("%d\n",c);
    }
    return 0;
}
