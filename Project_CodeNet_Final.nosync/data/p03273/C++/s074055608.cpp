#include <stdio.h>

int main()
{
    int h,w;
    char a[100][101];
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++) scanf("%s",&a[i]);

    bool x[100]={};
    bool y[100]={};
    for(int i=0;i<h;i++)
    {
        bool tmp=false;
        for(int j=0;j<w;j++)
        {
            if(a[i][j]=='#')
            {
                tmp=true;
                break;
            }
        }
        if(tmp) x[i]=true;
    }
    for(int i=0;i<w;i++)
    {
        bool tmp=false;
        for(int j=0;j<h;j++)
        {
            if(a[j][i]=='#')
            {
                tmp=true;
                break;
            }
        }
        if(tmp) y[i]=true;
    }

    for(int i=0;i<h;i++)
    {
        bool judge=false;
        for(int j=0;j<w;j++)
        {
            if(x[i]&&y[j]) 
            {
                printf("%c",a[i][j]);
                judge=true;
            }
        }
        if(judge)printf("\n");
    }
}