#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
#define N 1000010


int main()
{
    int n,x;
    scanf("%d",&n);
    int ans=0,maxx=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>=maxx)
            ans++,maxx=x;
    }
    printf("%d\n",ans);
    return 0;
}
