#include <stdio.h>
#include <algorithm>
#include <list>
using namespace std;
list <int> to[9];
int arr[9];
int node,edge;
int ans=0;
int where(int in,int what)
{
    for (list<int>::iterator it = to[in].begin();it!=to[in].end();it++)
    {
        if (*it == what)
        {
            return 1;
        }
    }
    return 0;
}
void calcu(int arr[])
{
    for (int i=1;i<node;i++)
    {
        if (where(arr[i],arr[i+1])==0)
        {
            return;
        }
    }
    ans++;
    return;
}
main()
{
    scanf("%d %d",&node,&edge);
    for (int i=0;i<edge;i++)
    {
        int one,two;
        scanf("%d %d",&one,&two);
        to[one].push_back(two);
        to[two].push_back(one);
    }
    for (int i=1;i<=node;i++)
    {
        arr[i]=i;
    }
    do
    {
        calcu(arr);
    }
    while (next_permutation(arr+2,arr+node+1));
    printf("%d",ans);
}
