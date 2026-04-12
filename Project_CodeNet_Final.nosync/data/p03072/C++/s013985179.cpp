#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,a[100],k=0,i,flag,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=i;j>=0;j--)
        {
         if(a[i]<a[j])
            flag=1;
        }
        if(flag==0)
            k++;
    }
    printf("%d",k);
    return 0;
}