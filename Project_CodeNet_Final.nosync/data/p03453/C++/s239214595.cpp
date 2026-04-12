#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
struct P
{
    int x;
    int y,z;
    bool operator<(const P &a)const
    {
       return x>a.x;
    }
};
struct S
{
    int x,y;
};
const int N=2e5+500;
vector<P> v[N];
int a,c,i,b,k,d,n,m,e=1987654321;
int l[N],o[N];
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0},dz[10]={0,0,0,0,1,-1};
ll x,y,z[5][N],j[5][N],mod=1000000007;
P u[N];
stack<S> s;
queue<int> q;
string r,r1,r2;
bool as(int a,int b)
{
    return a>b;
}
ll f(int i,int n)
{
    if(l[i]==n) return 1;
    if(z[i][n]) return z[i][n];
    ll h,x=0;
    for(h=0;h<v[n].size();h++)
         if(j[i][n]==j[i][v[n][h].x]+v[n][h].y)   x+=f(i,v[n][h].x),x%=mod;
    return z[i][n]=x;
}
int main()
{
    int t,u,h;
    a=ri(),b=ri(),l[1]=ri(),l[2]=ri();
    for(t=1;t<=b;t++)
    {
        n=ri();m=ri(),i=ri();
        v[n].push_back({m,i});
        v[m].push_back({n,i});
    }
    memset(j,-1,sizeof(j));
    for(u=1;u<=2;u++)
    {
        j[u][l[u]]=0;
        q.push(l[u]);
        for(;q.size();q.pop())
        {
            for(h=0;h<v[q.front()].size();h++)
            if(j[u][v[q.front()][h].x]<0||j[u][v[q.front()][h].x]>j[u][q.front()]+v[q.front()][h].y)
            {
                j[u][v[q.front()][h].x]=j[u][q.front()]+v[q.front()][h].y;
                q.push(v[q.front()][h].x);
            }
        }
    }
    y=f(1,l[2]);
    x=y*y%mod;
    for(t=1;t<=a;t++)
        if(j[1][t]==j[2][t]&&j[2][t]*2==j[1][l[2]])    x-=f(1,t)*f(1,t)%mod*f(2,t)%mod*f(2,t)%mod,x+=mod,x%=mod;
    for(t=1;t<=a;t++)
        for(h=0;h<v[t].size();h++)
            if(v[t][h].y+j[1][t]+j[2][v[t][h].x]==j[1][l[2]]&&max(j[1][t],j[2][v[t][h].x])<min(j[1][t],j[2][v[t][h].x])+v[t][h].y)
                x-=f(1,t)*f(1,t)%mod*f(2,v[t][h].x)%mod*f(2,v[t][h].x)%mod,x+=mod,x%=mod;
    printf("%lld\n",x);
}