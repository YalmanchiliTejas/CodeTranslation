#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=105;
const int maxm=5e2+5;
const int maxq=55;
const int INF=0x3f3f3f3f;
char s[maxn][maxn];
int row[maxn];
int col[maxn];
int main()
{
    int h,w;
    while(~scanf("%d%d",&h,&w))
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=1;i<=h;i++)
        {
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=h;i++)
        {
            int f=1;
            for(int j=1;j<=w&&f;j++)
            {
                if(s[i][j]=='#') f=0;
            }
            if(f) row[i]=1;
        }
        for(int i=1;i<=w;i++)
        {
            int f=1;
            for(int j=1;j<=h&&f;j++)
            {
                if(s[j][i]=='#') f=0;
            }
            if(f) col[i]=1;
        }
        for(int i=1;i<=h;i++)
        {
            if(row[i]) continue;
            for(int j=1;j<=w;j++)
            {
                if(!col[j]) printf("%c",s[i][j]);
            }
            puts("");
        }
    }
}
