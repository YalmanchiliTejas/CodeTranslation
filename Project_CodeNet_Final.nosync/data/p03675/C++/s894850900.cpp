#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    memset(a,-1,sizeof(a));
    int l=100000,r=100000;
    int r_tag=0;
    int i;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if (r_tag)
        {
            l--;
            a[l]=x;
        }
        else
        {
            a[r]=x;
            r++;
        }
        r_tag^=1;
    }
    if (r_tag==0)
    {
        for (i=0;i<=200000;i++)
        {
            if (a[i]!=-1) printf("%d ",a[i]);
        }
    }
    else
    {
        for (i=200000;i>=0;i--)
        {
            if (a[i]!=-1) printf("%d ",a[i]);
        }
    }
    return 0;
}
