#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    char b[100];
}qq;
int main()
{

    int n;
    scanf("%d",&n);
    int b[50];
    int c[50];
    memset(b,0,sizeof(b));
    qq a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].b);
    }
    for(int i=0;a[0].b[i];i++)
    {
        b[a[0].b[i]-'a']++;
    }
    for(int j=1;j<n;j++)
    {
       memset(c,0,sizeof(c));
       for(int w=0;a[j].b[w];w++)
       {
           c[a[j].b[w]-'a']++;
       }
       for(int jj=0;jj<30;jj++)
       {
           b[jj]=min(b[jj],c[jj]);
       }

    }

    int flag=0;
    for(int i=0;i<30;i++)
    {
        if(b[i]!=0)
        {
            flag=1;
            for(int j=1;j<=b[i];j++)
            {
                printf("%c",i+'a');
            }
        }
    }
    if(flag==0)
    {
        printf(" \n");
    }
    else
    {
        printf("\n");
    }

    return 0;
}
