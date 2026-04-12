#include<cstdio>
using namespace std;
char s[105][105];
int vis[105],cnt[105];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%s",s[i]);
    for(int i=0;i<n;++i)
    {
        int f=0;
        for(int j=0;j<m;++j)
            f+=s[i][j]=='#';
        if(!f)vis[i]=1;
    }
    for(int j=0;j<m;++j)
    {
        int f=0;
        for(int i=0;i<n;++i)
            f+=s[i][j]=='#';
        if(!f)cnt[j]=1;
    }
    for(int i=0;i<n;++i)
        if(!vis[i])
        {
            for(int j=0;j<m;++j)
                if(!cnt[j])
                    putchar(s[i][j]);
            puts("");
        }
    return 0;
}