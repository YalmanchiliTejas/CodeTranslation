# include<bits/stdc++.h>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define eps 1e-8
# define MOD 1000000007
# define INF 1000000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
# define AU(i,x)    for(auto i=x.begin(); i!=x.end(); ++i)
# define ALL(A) A.begin(),A.end()
# define bug puts("H");
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mp make_pair
# define pb push_back
typedef pair<int,int> PII;
typedef vector<int> VI;
# pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long LL;
inline char nc(){
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int Scan(){
    char ch=nc();int sum=0, f=1;
    if (ch=='-') f=-1, ch=nc();
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*f;
}
int ps4[4][2]={0,1,0,-1,1,0,-1,0};
int ps8[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,-1,-1,1};
inline int min(int a,int b,int c) {return min(a,min(b,c));}
inline int max(int a,int b,int c) {return max(a,max(b,c));}
inline int min(int a,int b,int c,int d){return min(min(a,b,c),d);}
inline int max(int a,int b,int c,int d){return max(max(a,b,c),d);}
//struct Edge{int p, next, w;}edge[maxn];
//inline add_edge(int u, int v, int w){edge[cnt]=Edge{v,head[u],w}; head[u]=cnt++;}
const int N=100005;
///Code begin..................................................................


int main ()
{
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",(a-c)/(b+c));
}
