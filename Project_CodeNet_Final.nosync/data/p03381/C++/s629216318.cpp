#include<bits/stdc++.h>
using namespace std;
int a[200005];
int e[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        e[i]=a[i];
    }
    sort(e,e+n);
    int mid1=n/2-1,mid2=n/2;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=e[mid1])
        {
            printf("%d\n",e[mid2]);
        }
        else if(a[i]>=e[mid2])
        {
            printf("%d\n",e[mid1]);
        }
    }
}