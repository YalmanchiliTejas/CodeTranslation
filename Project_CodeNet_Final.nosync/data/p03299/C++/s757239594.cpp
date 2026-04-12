#include<bits/stdc++.h>
#define ll long long
#define ljc 1000000007
#define inv2 500000004
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
inline ll fast_pow(ll a,ll b,ll p){
	ll t=1;
	if (b==-1) return 0;
	while (b){
		if (b&1ll) t=t*a%p;
		b>>=1ll;a=a*a%p;
	}
	return t;
}
int h[201010],n;
namespace ST{
	int f[201010][20],id[201010][20];
	inline pair<int,int> query(int l,int r){
		if (l>r) return make_pair(1e9+1,1e9+1);
		int k=log2(r-l+1);
		if (f[l][k]<=f[r-(1<<k)+1][k]){
			return make_pair(f[l][k],id[l][k]);
		}else{
			return make_pair(f[r-(1<<k)+1][k],id[r-(1<<k)+1][k]);
		}
	}
	inline void init(){
		for (int i=1;i<=n;i++) f[i][0]=h[i],id[i][0]=i;
		for (int j=1;j<=19;j++){
			for (int i=1;i+(1<<j)-1<=n;i++){
				int l=i,r=i+(1<<(j-1));
				if (f[l][j-1]<=f[r][j-1]){
					id[l][j]=id[l][j-1];
					f[l][j]=f[l][j-1];
				}else{
					id[l][j]=id[r][j-1];
					f[l][j]=f[r][j-1];
				}
			}
		}
		return;
	}
}
struct node{
	ll x,y;
};
inline node init(ll xx,ll yy){
	node x;x.x=xx,x.y=yy;return x;
}
inline node dp(int l,int r,int H){
	if (l>r) return init(0,0);
//	if (l>r) return init(0,0,0);
//	if (l==r) return init(0,fast_pow(2,h[l]-H-1,ljc),fast_pow(2,h[l]-H-1,ljc));
//	ll resr=0,resb=0,res1=0;
//	int id=ST::query(l,r).second;
//	node ls=dp(l,id-1,h[id]),rs=dp(id+1,r,h[id]);
//	if (id==l){
//		res1=rs.x*2ll%ljc;
//		resb=rs.R;
//		resr=rs.B;
//	}else if (id==r){
//		res1=ls.x*2ll%ljc;
//		resb=ls.B;
//		resr=ls.R;
//	}else{
//		if ((id-l)%2==0){
//			ll tmp=ls.R*rs.B%ljc+ls.B*rs.R%ljc;
//			if (h[id]==H) resb=resr=tmp;
//			else resr=resb=tmp*fast_pow(2ll,h[id]-H-1,ljc)%ljc;
//		}else{
//			ll tmp=ls.B*rs.B%ljc+ls.R*rs.R%ljc;
//			if (h[id]==H) resb=resr=tmp;
//			else resr=resb=tmp*fast_pow(2ll,h[id]-H-1,ljc)%ljc;
//		}
////	}
//	return init(res1,resr,resb);
	vector<int> now;now.clear();
	pair<ll,ll> tmp=ST::query(l,r);
	ll xxx=tmp.first;
	for (int id=tmp.second;id<=r&&h[id]==xxx;id=ST::query(id+1,r).second) 
		now.push_back(id);
	ll resx=2,resy=0;
	/*if (tmp.second==l) resx=2,resy=0;
	else */if (tmp.second!=l){
		node son=dp(l,tmp.second-1,xxx);
		resx=son.x*2%ljc;
		resy=son.y;
		resy=(resy*2%ljc+resx)%ljc;
	}
	for (int i=1;i<(int)now.size();i++){
		int L=now[i-1],R=now[i];
		if (R-L>1){
			node son=dp(L+1,R-1,xxx);
		resy=(resx*(son.x+son.y)%ljc+resy*(2*son.x%ljc+son.y%ljc)%ljc)%ljc;
		resx=resx*son.x%ljc;
		}
		resy=(resy*2%ljc+resx)%ljc;
	}
	if (r-now.back()>=1){
		node son=dp(now.back()+1,r,xxx);
		resy=(resx*(son.x+son.y)%ljc+resy*(2*son.x%ljc+son.y%ljc)%ljc)%ljc;
		resx=resx*son.x%ljc;
	} 
	return init(resx*fast_pow(2,xxx-H-1,ljc)%ljc,resy);
}
/*
4
2 3 5 4

3
1 3 2
*/
signed main(){
	n=read();
	for (int i=1;i<=n;i++) h[i]=read();
	ST::init();
	node tmp=dp(1,n,0);
	printf("%lld\n",(tmp.x+tmp.y)%ljc);
	return 0;
}

