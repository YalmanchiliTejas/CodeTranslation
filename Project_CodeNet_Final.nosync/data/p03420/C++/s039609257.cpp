#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c<'0' || c>'9'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	ll f=1;
	while((c=getchar())!='-' && (c<'0' || c>'9'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
int main(){
	int n=read(),m=read();
	ll ans=0;
	REP(i,m+1,n){
		ans+=1ll*(i-m)*(n/i);
		ans+=max(n%i-m+1,0);
		if(m==0) ans--;
	}
	printf("%lld\n",ans);
	return 0;
}
