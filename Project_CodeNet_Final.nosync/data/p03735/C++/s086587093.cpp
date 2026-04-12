#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=2e5+11;
int n;
pii p[N];
int main(){
	n=rd();
	int mx=-inf,mi=inf;
	rep(i,1,n){
		p[i].x=rd();
		p[i].y=rd();
		if(p[i].x>p[i].y)swap(p[i].x,p[i].y);
		mx=max(mx,p[i].y);
		mi=min(mi,p[i].y);
	}
	sort(p+1,p+n+1);
	ll ans=1LL*(mx-mi)*(p[n].x-p[1].x);
	int mii,mxx;
	mxx=mii=p[1].y;
	rep(i,2,n){
		ll tmp=1LL*(mx-p[1].x)*( max(mxx,p[n].x) - min(mii, p[i].x) );
		ans=min(ans,tmp);
		mxx = max(mxx, p[i].y);
		mii = min(mii, p[i].y);
	}
	cout<<ans<<endl;
}