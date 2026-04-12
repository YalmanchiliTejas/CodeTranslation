#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=110;
char s[maxn][maxn];
int h,w;

int main()
{
    //freopen("1.txt","r",stdin);
    while (scanf("%d%d",&h,&w)!=EOF)
    {
        memset(s,0,sizeof(s));
        for (int i=0;i<h;i++) scanf("%s",s[i]);
        for (int i=0;i<h;i++)
        {
            if (s[i][0]=='.')
            {
                bool f=true;
                for (int j=0;j<w;j++)
                {
                    if (s[i][j]==0) continue;
                    if (s[i][j]!='.')
                    {
                        f=false;
                        break;
                    }
                }

                if (f) for (int j=0;j<w;j++) s[i][j]=0;
            }
        }

        for (int i=0;i<w;i++)
        {
            if (s[0][i]=='.' || s[0][i]==0)
            {
                bool f=true;
                for (int j=0;j<h;j++)
                {
                    if (s[j][i]==0) continue;
                    if (s[j][i]!='.')
                    {
                        f=false;
                        break;
                    }
                }

                if (f) for (int j=0;j<h;j++) s[j][i]=0;
            }
        }

        for (int i=0;i<h;i++)
        {
            bool f=false;
            for (int j=0;j<w;j++)
                if (s[i][j]!=0)
                {
                    printf("%c",s[i][j]);
                    f=true;
                }
            if (f) puts("");
        }
    }
    return 0;
}

