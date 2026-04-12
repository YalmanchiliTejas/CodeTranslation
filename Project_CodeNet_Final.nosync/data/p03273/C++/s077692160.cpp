#include<stdio.h>
int main()
{
    int p,q;
    char a[1000][1000];
    scanf("%d %d%*c",&p,&q);
    int i,j;
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%c",&a[i][j]);
        }
        a[i][j]='\0';
        scanf("%*c");
    }
    for(i=0;i<p;i++)
    {
        int r=0;
        for(j=0;j<q;j++)
        {
            if(a[i][j]!='#') r++;
        }
        if(r==q)
        {
            for(j=0;j<q;j++) a[i][j]='0';
        }
    }
    for(i=0;i<q;i++)
    {
        int r=0;
        for(j=0;j<p;j++)
        {
            if(a[j][i]!='#') r++;
        }
        if(r==p)
        {
            for(j=0;j<p;j++) a[j][i]='0';
        }
    }
    for(i=0;i<p;i++)
    {
        int r=0;
        for(j=0;j<q;j++)
        {
            if(a[i][j]!='0')
            {

            printf("%c",a[i][j]);
            r++;
            }
        }
       if(r!=0) printf("\n");
    }
    return 0;
}
