#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
int main()
{
    int n,i;
    scanf("%d",&n);getchar();
    char a[100005];
    for(i=1;i<=n;i++)
        scanf("%c",&a[i]);
    int k;
    scanf("%d",&k);
    for(i=1;i<=n;i++)
    {
        if(a[i]!=a[k])
            a[i]='*';
    }
    for(i=1;i<=n;i++)
        printf("%c",a[i]);
    return 0;
}
