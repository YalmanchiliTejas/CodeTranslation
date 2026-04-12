#pragma GCC optimize(2)
#pragma G++ optimize(2)
#include<bits/stdc++.h>
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define ms(a) memset(a,0,sizeof(a))
#define repi(i,a,b) for(register ll i=a,bbb=b;i<=bbb;++i)
#define repd(i,a,b) for(register int i=a,bbb=b;i>=bbb;--i)
#define reps(s) for(register int i=head[s],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define ce(i,r) i==r?'\n':' '
#define pb push_back 
#define all(x) x.begin(),x.end()
#define gmn(a,b) a=min(a,b)
#define gmx(a,b) a=max(a,b)
#define fi first
#define se second
#define pr(x) cout<<#x<<": "<<x<<endl
using namespace std;
std::mt19937 rnd(time(0));//std::mt19937_64 rnd(time(0));
typedef long long ll;
typedef double db;
inline int qi(){
    int f=0,fu=1; char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-')fu=-1; c=getchar(); }
    while(c>='0'&&c<='9'){ f=(f<<3)+(f<<1)+c-48; c=getchar(); }
    return f*fu;
}
inline ll ql(){
	ll f=0;int fu=1; char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-')fu=-1; c=getchar(); }
    while(c>='0'&&c<='9'){ f=(f<<3)+(f<<1)+c-48; c=getchar(); }
    return f*fu;
}
inline ll ceil_div(ll a,ll b){ return (a+b-1)/b; }
//start!
const int MAX_N=1e5+5;
int pos[MAX_N];
ll sum[MAX_N];
int main()
{
	ll n=ql(),x=ql(),m=ql(); sum[1]=x,x%=m,pos[x]=1;
	ll loop=-1,len,before;
	repi(i,2,n){
		x=x*x%m;
		if(pos[x]){ before=pos[x]-1,loop=sum[i-1]-sum[pos[x]-1],len=i-pos[x]; break; } 
		pos[x]=i;
		sum[i]=sum[i-1]+x;
		
	}
	if(loop==-1) printf("%lld\n",sum[n]);
	else{
		ll ans=sum[before]+((n-before)/len)*loop;
		int left=(n-before)%len;
		ans+=sum[before+left]-sum[before];
		printf("%lld\n",ans);
	}
	return 0;
}
