/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=200000;
int n,m;
vector<pair<int,int> > rg[N+1];
struct segtree{
	struct node{int l,r,mx,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define mx(p) nd[p].mx
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;mx(p)=lz(p)=0;
		if(l==r)return;
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p)){
			mx(p<<1)+=lz(p);mx(p<<1|1)+=lz(p);
			lz(p<<1)+=lz(p);lz(p<<1|1)+=lz(p);
			lz(p)=0;
		}
	}
	void sprup(int p){mx(p)=max(mx(p<<1),mx(p<<1|1));}
	void _add(int l,int r,int v,int p=1){
		if(l<=l(p)&&r>=r(p)){mx(p)+=v;lz(p)+=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)_add(l,r,v,p<<1);
		if(r>mid)_add(l,r,v,p<<1|1);
		sprup(p);
	}
	void add(int l,int r,int v){if(l<=r)_add(l,r,v);}
	int _mx(){return mx(1);}
}segt;
int dp[N+1][2];
signed main(){
	cin>>n>>m;
	while(m--){
		int l,r,a;
		scanf("%lld%lld%lld",&l,&r,&a);
		rg[r].pb(mp(l,a));
	}
	segt.init();
	for(int i=1;i<=n;i++){
		vector<pair<int,int> > &v=rg[i];
		v.pb(mp(i,inf));
		sort(v.begin(),v.end());
		int sum=0;
		for(int j=0;j+1<v.size();j++){
			sum+=v[j].Y;
			segt.add(v[j].X,v[j+1].X-1,sum);
		}
		dp[i][1]=max(dp[i-1][0],dp[i-1][1])+sum;
		dp[i][0]=segt._mx();
		segt.add(i,i,dp[i][1]);
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
/*1
5 3
1 3 10
2 4 -10
3 5 10
*/