#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[10][10];
int b[10];
int nex[8][2]={1,0,0,1,-1,0,0,-1,1,1,-1,-1,-1,1,1,-1};
int main()
{
    int h,w;
    while(~scanf("%d%d",&h,&w))
    {
        for(int i=0; i<h; i++)
            scanf("%s",a[i]);
        int flag=0,cnt=0,nx,ny;
        for(int i=2; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(a[i][j]=='#')
                {
                    for(int pre=i-2; pre>=0; pre--)
                    {
                        if(a[pre][j]=='#')
                        {
                            for(int ii=pre;ii<i;ii++)
                            {
                                if(a[ii][j]!='#') {flag=1;break;}
                            }
                        }
                        if(flag) break;
                    }
                }
                if(flag) break;
            }
        }
        for(int i=1;i<h;i++)
        {
            cnt=0;
            for(int j=0;j<w;j++)
            {
                if(a[i][j]=='#'&&a[i-1][j]=='#') cnt++;
            }
            if(cnt>1) flag=1;
        }
        if(flag) puts("Impossible");
        else puts("Possible");
    }
    return 0;
}
