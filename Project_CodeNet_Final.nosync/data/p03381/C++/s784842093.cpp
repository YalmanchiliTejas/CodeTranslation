#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=200020;

int num[maxn],st[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            st[i]=num[i];
        }
        sort(num+1,num+1+n);


        int mid=n/2;
        for(int i=1;i<=n;i++)
        {
            int p=lower_bound(num+1,num+1+n,st[i])-num;
            if(p+p<=n)
                printf("%d\n",num[mid+1]);
            else
                printf("%d\n",num[mid]);
        }
    }
    return 0;
}
