#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
typedef std::pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const int maxn=2005;
int n,a[maxn<<2],f[maxn][maxn],maxd[maxn];
struct node {int x,y,z;} que[maxn*maxn];
int tail,maxx,extadd;

void add(int x,int y,int z)
{
    que[++tail]=(node){x,y,z};
}

void update()
{
    for(int i=1;i<=tail;i++)
    {
        node d=que[i];
        f[d.x][d.y]=max(f[d.x][d.y],d.z);
        f[d.y][d.x]=max(f[d.y][d.x],d.z);
        maxx=max(maxx,d.z);
        maxd[d.x]=max(maxd[d.x],d.z);
        maxd[d.y]=max(maxd[d.y],d.z);
    }
    tail=0;
}

int main()
{
    n=read();
    REP(i,1,n*3) a[i]=read();

    REP(i,1,n) REP(j,1,n) f[i][j]=-10000000;
    REP(i,1,n) maxd[i]=-100000000;
    f[a[1]][a[2]]=f[a[2]][a[1]]=0;
    maxd[a[1]]=maxd[a[2]]=0;

    for(int i=1;i<n;i++)
    {
        if(a[i*3]==a[i*3+1] && a[i*3]==a[i*3+2])
        {
            extadd++;
            continue;
        }
        if(a[i*3]==a[i*3+1] || a[i*3]==a[i*3+2] || a[i*3+1]==a[i*3+2])
        {
            int p=a[i*3],q=a[i*3+1];
            if(p==q) q=a[i*3+2];
            else if(a[i*3+2]==q) swap(p,q);
            for(int k=1;k<=n;k++)
                add(k,q,f[k][p]+1);
        }

        {
            int p=a[i*3],q=a[i*3+1],r=a[i*3+2];
            add(q,r,f[p][p]+1);
            add(q,p,f[r][r]+1);
            add(p,r,f[q][q]+1);
        }

        int p=a[i*3],q=a[i*3+1],r=a[i*3+2];
        add(p,q,maxx);
        add(p,r,maxx);
        add(q,r,maxx);

        REP(j,0,2)
        {
            int p=a[i*3+j];
            for(int k=1;k<=n;k++)
                add(k,p,maxd[k]);
        }

        update();
        //REP(i,1,n) REP(j,1,n) cout<<f[i][j]<<' ';
        //cout<<endl<<endl;
    }
    REP(i,1,n) REP(j,1,n) maxx=max(maxx,f[i][j]);
    maxx=max(maxx,f[a[n*3]][a[n*3]]+1);
    cout<<maxx+extadd;

    return 0;
}
