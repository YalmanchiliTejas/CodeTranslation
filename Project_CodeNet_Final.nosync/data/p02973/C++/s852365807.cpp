#include <iostream>
#include <cstdio>
#include<queue>
using namespace std;
int n;
int head;
int p[100100],a[100100];
int find(int l,int r,int x)
{
    if(x<=p[l])  return -1;
    int mid;
    while(l<=r)
    {
        if(l==r)  return l;
        if(l==r-1)
        {
            if(x>p[l] && x<=p[r])  return l;
            return r;
        }
        mid=l+r>>1;
        if(p[mid]>=x)  r=mid-1;
        else    l=mid;
    }
    return mid;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
    int tot=100050;
    head=tot;
    p[head]=a[1];
    for(int i=2;i<=n;i++)
    {
        int k=find(head,tot,a[i]);
        if(k>0)  p[k]=a[i];
        else  p[--head]=a[i];
    }
    cout<<tot-head+1<<endl;
    return 0;
}