# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <queue>
# include <stack>
# include <map>
# include <math.h>
# include <algorithm>
using namespace std;
# define MAXN 55
# define MAXM 100005
# define INF 1000000000
# define MIN(a,b) (a)>(b)?(b):(a)
# define MAX(a,b) (a)<(b)?(b):(a)
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FO(i,a,n) for(int i=a; i<n; ++i)
# define bug puts("H");
typedef long long LL;
int _MAX(int a, int b){return a>b?a:b;}
int _MIN(int a, int b){return a>b?b:a;}

int a, b, f[10], l[10];
char s[10][10];

int main()
{
    scanf("%d%d",&a,&b);
    FO(i,0,a) scanf("%s",s[i]);
    mem(f,-1); mem(l,-1);
    if (s[0][0]!='#'||s[a-1][b-1]!='#') {puts("Impossible"); return 0;}
    FO(i,0,a) {
        f[i]=0;
        int flag=0;
        FO(j,0,b) {
            if (flag&&s[i][j]=='#'&&s[i][j-1]!='#') {puts("Impossible"); return 0;}
            if (s[i][j]=='#'&&flag==0) l[i]=j;
            if (s[i][j]=='#') f[i]=j, flag=1;
        }
    }
    FO(i,1,a) {
        if (l[i]<f[i-1]||l[i]==-1||f[i]==-1) {puts("Impossible"); return 0;}
    }
    puts("Possible");
}
