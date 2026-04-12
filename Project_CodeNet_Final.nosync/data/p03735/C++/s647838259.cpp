#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define el putchar('\n')
#define ta putchar('	')
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=200010;
const ll Inf=1e18;
int n;
pll a[N],b[N<<1];
#define fi first
#define se second
set<pll>s1,s2;

inline ll calc(){return ((*s1.rbegin()).fi-(*s1.begin()).fi)*((*s2.rbegin()).fi-(*s2.begin()).fi);}

int main()
{
	n=rd();
	fo(i,1,n){
		ll x=rd(),y=rd();
		if(x>y)swap(x,y);
		a[i]=pll(x,y);
		s1.insert(pll(x,i));
		s2.insert(pll(y,i));
	}
	ll mn=calc();
	fo(i,1,n){
		auto x=*s1.begin();
		auto y=pll(a[x.se].se,x.se);
		if(x==y)break;
		s1.erase(x);s2.erase(y);
		s1.insert(y);s2.insert(x);
		mn=min(calc(),mn);
	}
	printf("%lld\n",mn);
	return 0;
}
