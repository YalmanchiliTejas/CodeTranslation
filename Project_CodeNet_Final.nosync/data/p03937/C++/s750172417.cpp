#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define debug(a) cout<<a<<endl
#define clr(a) memset(a,0,sizeof(a))
#define clrne(a) memset(a,-1,sizeof(a))
#define clrinf(a) memset(a,0x3f,sizeof(a))
#define clrneinf(a) memset(a,0xc0,sizeof(a))
#define pb(a) push_back(a)
#define maxn 20
#define mod 1000000007
#define eps 1e-9
#define inf 0x7fffffff
char mat[maxn][maxn];
int maxi[maxn];
int mini[maxn];
int main()
{
//  freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i<=n; i++)
        for (int j  =1; j<=m; j++)
            scanf(" %c",&mat[i][j]);
    clrinf(mini);
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
            if (mat[i][j]=='#')
            {
                maxi[i] = j;
                mini[i] = min(mini[i],j);
            }
    }
    int flag = 1;
    for (int i = 1; i<=n; i++)
    {
        int cnt = 0;
        for (int j = 1; j<=m; j++)
            if (mat[i][j]=='#') cnt++;
        if (cnt==0) flag = 0;
    }
//    for (int i = 1;i<=n;i++)
//        printf("%d %d\n",maxi[i],mini[i]);
    for (int i = 2; i<=n; i++)
        if (mini[i]!=maxi[i-1]) flag = 0;
    if (flag) printf("Possible\n");
    else printf("Impossible");
    return 0;
}
