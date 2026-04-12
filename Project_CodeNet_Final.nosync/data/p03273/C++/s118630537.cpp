#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string s[1100],ans[1100];
bool hang[1100],lie[1100];
int h,w;
int main()
{
    scanf("%d%d",&h,&w);
    for (int i=0;i<h;i++) cin >> s[i];
    memset(hang,1,sizeof(hang));
    memset(lie,1,sizeof(lie));
    for (int i=0;i<h;i++)
    {
        bool all=1;
        for (int j=0;j<w;j++)
            if (s[i][j]=='#') {all=0;break;}
        if (all) hang[i]=0;
    }
    for (int i=0;i<w;i++)
    {
        bool all=1;
        for ( int j=0;j<h;j++)
            if (s[j][i]=='#') {all=0;break;}
        if (all) lie[i]=0;
    }
 
    for (int i=0;i<h;i++)
    {
        bool out=0;
        for (int j=0;j<w;j++)
            if ((hang[i]) && (lie[j])) {cout << s[i][j];out=1;}
        if (out) cout << endl;
    }
    return 0;
}
