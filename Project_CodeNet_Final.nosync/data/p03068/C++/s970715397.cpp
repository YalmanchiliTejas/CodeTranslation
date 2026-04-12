#include<cstdio>
int main()
{
    int n,k;
    char a[50];
    scanf("%d%s%d",&n,a,&k);;
    k--;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=a[k])
            printf("*");
        else
            printf("%c",a[i]);
    }
    return 0;
}
