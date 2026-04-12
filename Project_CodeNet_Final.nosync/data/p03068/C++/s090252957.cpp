#include<stdlib.h>
#include<stdio.h>

int main()
{
    int n,k,i;
    char *s;
    char a;
    scanf("%d",&n);
    s=(char*)malloc(n*sizeof(char));
    scanf("%s",s);
    scanf("%d",&k);
    a=s[k-1];
    for(i=0;i<n;i++)
    {
        if(a!=s[i]) s[i]='*';
    }
    printf("%s",s);
    free(s);
}