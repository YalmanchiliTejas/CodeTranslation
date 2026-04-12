#include<stdio.h>
#include<string.h>
#define maxn 60
#define N 1010
char map[maxn][maxn];
long long nt,ti;
bool use[maxn][maxn];
int n,m,q;
struct task
{
    int r,c;
}s[N];
struct visit
{
    int cnt;
    long long int ti[N];
}vis[maxn][maxn];
struct mat
{
    long long int keep;
    long long int on;
    long long int off;
}cost[maxn][maxn];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
long long min(long long a,long long b)
{
    return a>b?b:a;
}
long long int get()
{
    char ch;
    while (ch=getchar(),ch<'0'||ch>'9');
    long long sum=ch-'0';
    while (ch=getchar(),ch>='0'&&ch<='9')
        sum=sum*10+ch-'0';
    return sum;
}
int get2()
{
    char ch;
    while (ch=getchar(),ch<'0'||ch>'9');
    int sum=ch-'0';
    while (ch=getchar(),ch>='0'&&ch<='9')
        sum=sum*10+ch-'0';
    return sum;
}
void readin()
{
    for (int i=1;i<=n;i++)
        scanf("%s",map[i]+1);
    //for (int i=1;i<=n;i++)
    //    printf("%s\n",map[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cost[i][j].keep=get();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cost[i][j].on=get();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cost[i][j].off=get();
   /* for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            printf("%I64d %I64d %I64d\n",cost[i][j].keep,cost[i][j].on,cost[i][j].off);*/
    for (int i=1;i<=q;i++)
        s[i].r=get2(),s[i].c=get2(),s[i].r++,s[i].c++;
}
bool ok(int r,int c)
{
    if (r<1||r>n||c<1||c>m)return false;
    if (map[r][c]=='#')return false;
    return use[r][c];
}
bool dfs (int r,int c,task end,long long  tim)
{
    if (r==end.r&&c==end.c)
    {
        nt=tim;
        return true;
    }
    use[r][c]=0;
    vis[r][c].ti[++vis[r][c].cnt]=tim;
    for (int i=0;i<=4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];
        if (ok(nr,nc))
        {
            if (dfs(r+dr[i],c+dc[i],end,tim+1))return true;
        }
    }
    use[r][c]=1;
    vis[r][c].cnt--;
    return false;
}
void work()
{
    nt=0ll;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            vis[i][j].cnt=0;
    for (int i=1;i<q;i++)
    {
        memset(use,1,sizeof use);
        dfs(s[i].r,s[i].c,s[i+1],nt);
    }
    vis[s[q].r][s[q].c].ti[++vis[s[q].r][s[q].c].cnt]=nt;
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            long long sum=0;
            //printf("cnt=%d : ",vis[i][j].cnt);
            for (int k=1;k<vis[i][j].cnt;k++)
            {
                sum+=min(cost[i][j].on+cost[i][j].off,cost[i][j].keep*(vis[i][j].ti[k+1]-vis[i][j].ti[k]));
                //printf("%lld ",vis[i][j].ti[k]);
                //printf("\n");
            }
            if (vis[i][j].cnt)sum+=cost[i][j].off+cost[i][j].on;
            ans+=sum;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    while (scanf("%d %d %d",&n,&m,&q)!=EOF)
    {
        readin();
        work();
    }
    return 0;
}
/*
3 3 5
***
*##
**#
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 0
2 1
0 2
2 0
0 0
*/