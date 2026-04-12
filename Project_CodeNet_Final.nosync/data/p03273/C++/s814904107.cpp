#include <bits/stdc++.h>
using namespace std;
char s[300][300];
bool chk[300][300];
int main()
{
    int h,w; cin>>h>>w;
    for(int i=0;i<h;i++) scanf("%s",s[i]);
    for(int i=0;i<h;i++)
    {
        bool flag=false;
        for(int j=0;j<w;j++) if(s[i][j]=='#') flag=true;
        if(!flag) for(int j=0;j<w;j++) chk[i][j]=true;
    }
    for(int i=0;i<w;i++)
    {
        bool flag=false;
        for(int j=0;j<h;j++) if(s[j][i]=='#') flag=true;
        if(!flag) for(int j=0;j<h;j++) chk[j][i]=true;
    }
    for(int i=0;i<h;i++)
    {
        bool flag=false;
        for(int j=0;j<w;j++) if(!chk[i][j]) flag=true,printf("%c",s[i][j]);
        if(flag) puts("");
    }
}
