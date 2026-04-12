#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int x[200010],y[200010];
struct card{int x,t;}s[400010];
il bool operator<(const card&a,const card&b){return a.x<b.x;}
int main(){
#ifdef WOSHISB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=0;
	for(int i=1;i<=n;++i){
		x[i]=gi(),y[i]=gi();if(x[i]>y[i])std::swap(x[i],y[i]);
		s[++m]=(card){x[i],i},s[++m]=(card){y[i],i};
	}
	std::sort(s+1,s+m+1);
	ll ans=1e18;
	if(s[1].t!=s[m].t){//最大值和最小值放一个集合，要最小化另一个集合
		int t[200010]={0},sum=0;//另一个集合来自每一个卡包里的卡数量和来自的卡包数量
		int Lmin=s[1].x,Lmax=s[m].x,Rlen=2e9;
		for(int l=2,r=2;l<m;++l){
			while(r<m&&sum!=n){
				if(!t[s[r].t])++sum;
				++t[s[r].t];
				++r;
			}
			if(sum!=n)break;
			Rlen=std::min(Rlen,s[r-1].x-s[l].x);
			--t[s[l].t];
			if(!t[s[l].t])--sum;
		}
		ans=1ll*(Lmax-Lmin)*Rlen;
	}
	//最大值和最小值放不同的集合
	int Lmin=2e9,Lmax=0,Rmin=2e9,Rmax=0;
	for(int i=1;i<=n;++i){
		Lmin=std::min(x[i],Lmin);
		Lmax=std::max(x[i],Lmax);
		Rmin=std::min(y[i],Rmin);
		Rmax=std::max(y[i],Rmax);
	}
	ans=std::min(ans,1ll*(Lmax-Lmin)*(Rmax-Rmin));
	printf("%lld\n",ans);
	return 0;
}
