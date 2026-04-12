#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int hh[105],ww[105];
int main()
{
    int h,w;
    scanf("%d%d",&h,&w);
    memset(hh,0,sizeof(hh));
    memset(ww,0,sizeof(ww));
    for(int i=0;i<h;i++) scanf("%s",a[i]);
    for(int i=0;i<h;i++)
    {
        int flag=1;
        for(int j=0;j<w;j++)
        {
            if(a[i][j]=='#')
            {
                flag=0;
                break;
            }
        }
        if(flag) hh[i]=1;
    }
    for(int i=0;i<w;i++)
    {
        int flag=1;
        for(int j=0;j<h;j++)
        {
            if(a[j][i]=='#')
            {
                flag=0;
                break;
            }
        }
        if(flag) ww[i]=1;
    }
    for(int i=0;i<h;i++)
    {
        if(!hh[i])
        {
            int flag=1;
            for(int j=0;j<w;j++)
            {
                if(!ww[j]) flag=0,printf("%c",a[i][j]);
            }
            if(!flag) printf("\n");
        }
    }
}
