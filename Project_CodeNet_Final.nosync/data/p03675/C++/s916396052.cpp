#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,i,j,x,y;
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n%2==0)
        for(i=0,j=n-1,x=n/2,y=0;j>0||y<n;i++,j-=2,x++,y+=2)
    {
         if(j>0)b[i]=a[j];
         if(y<n)b[x]=a[y];
    }
    else
        for(i=0,j=n-1,x=n/2+1,y=1;j>=0||y<n;i++,j-=2,x++,y+=2)
    {
        if(j>=0)b[i]=a[j];
        if(y<n)b[x]=a[y];
    }
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}