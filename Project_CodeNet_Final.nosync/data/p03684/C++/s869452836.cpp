#include <bits/stdc++.h>
#define fi first
#define se second
#define lson (k<<1)
#define rson (k<<1|1)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define rep(i,s,t) for(int i=(s),_t=(t);i<_t;++i)
#define per(i,s,t) for(int i=(t)-1,_s=(s);i>=_s;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=(int)1e9+7;
template<class T>void rd(T &x)
{
	x=0;
	static char c;
	while(c=getchar(),c<48);
	do x=x*10+(c^48);
		while(c=getchar(),c>47);
}
void ptn(ll x)
{
	static char stk[65];
	int tp=0;
	for(;x;x/=10)stk[tp++]=x%10^48;
	per(i,0,tp)putchar(stk[i]);
	putchar('\n');
}
template<class T>inline void Max(T &a,T b)
{
	if(b>a)a=b;
}
template<class T>inline void Min(T &a,T b)
{
	if(b<a)a=b;
}
// EOT


const int N=(int)1e5+5;

int par[N];
pii dat[N];

int get_root(int u)
{
	return par[u]==u?u:par[u]=get_root(par[u]);
}

pii val_x[N],val_y[N];

int main()
{
	int n;
	cin>>n;
	static pii disc_x[N],disc_y[N];
	int tot_x=0,tot_y=0;
	rep(i,0,n)
	{
		rd(dat[i].fi),rd(dat[i].se);
		disc_x[tot_x++]=pii(dat[i].fi,i);
		disc_y[tot_y++]=pii(dat[i].se,i);
	}
	sort(disc_x,disc_x+tot_x);
	sort(disc_y,disc_y+tot_y);
	ll ans=0;
	static int refer_x[N],refer_y[N];
	rep(i,0,n)
	{
		refer_x[i]=disc_x[i].se;
		refer_y[i]=disc_y[i].se;
	}
	rep(i,0,tot_x-1)val_x[i]=pii(dat[refer_x[i+1]].fi-dat[refer_x[i]].fi,i);
	rep(i,0,tot_y-1)val_y[i]=pii(dat[refer_y[i+1]].se-dat[refer_y[i]].se,i);
	sort(val_x,val_x+tot_x-1);
	sort(val_y,val_y+tot_y-1);
	rep(i,0,n)par[i]=i;
	int i=0,j=0;
	for(;i<tot_x-1&&j<tot_y-1;)
	{
		if(val_x[i]<val_y[j])
		{
			if(get_root(refer_x[val_x[i].se])!=get_root(refer_x[val_x[i].se+1]))
			{
				ans+=val_x[i].fi;
				par[get_root(refer_x[val_x[i].se])]=get_root(refer_x[val_x[i].se+1]);
			}
			++i;
		}
		else
		{
			if(get_root(refer_y[val_y[j].se])!=get_root(refer_y[val_y[j].se+1]))
			{
				ans+=val_y[j].fi;
				par[get_root(refer_y[val_y[j].se])]=get_root(refer_y[val_y[j].se+1]);
			}
			++j;
		}
	}
	while(i<tot_x-1)
	{
		if(get_root(refer_x[val_x[i].se])!=get_root(refer_x[val_x[i].se+1]))
		{
			ans+=val_x[i].fi;
			par[get_root(refer_x[val_x[i].se])]=get_root(refer_x[val_x[i].se+1]);
		}
		++i;
	}
	while(j<tot_y-1)
	{
		if(get_root(refer_y[val_y[j].se])!=get_root(refer_y[val_y[j].se+1]))
		{
			ans+=val_y[j].fi;
			par[get_root(refer_y[val_y[j].se])]=get_root(refer_y[val_y[j].se+1]);
		}
		++j;
	}
	cout<<ans<<endl;
	return 0;
}
