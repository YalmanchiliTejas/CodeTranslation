#include<bits/stdc++.h>
#define M(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e2+7;
char a[maxn][maxn];
bool visx[maxn],visy[maxn];
int main()
{
    int h,w;
    M(visx,false);
    M(visy,false);
    scanf("%d%d",&w,&h);
    for(int i=0; i<w; i++)
    {
        scanf("%s",a[i]);
        for(int j=0;j<h;j++)
            if(a[i][j]=='#')visy[j]=visx[i]=true;
    }
    for(int i=0; i<w; i++)
    {
        if(visx[i])
        {
            for(int j=0;j<h;j++)
            {
                if(visy[j]) printf("%c",a[i][j]);
            }
            puts("");
        }
    }
}