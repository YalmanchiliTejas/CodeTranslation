#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef std::pair<int,int> P;
#define mk std::make_pair
#define fr first
#define sc second
inline int in()
{
	int k=0;char ch=gt;bool p=1;
	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return p?k:-k;
}
const int N=4e5+5;
ll ans=1e18;
int x[N],y[N],n,Mx,Mi,mx,mi,fz[N<<1],tot;
std::vector<int>G[N<<1];
inline void upd(int x,int i){if(x>Mx)Mx=x,mx=i;if(x<Mi)Mi=x,mi=i;}
inline void work1()
{
	int Lmx=-1e9,Rmx=-1e9,Lmi=1e9,Rmi=1e9;
	for(int i=1;i<=n;++i)
	{
		Lmx=std::max(Lmx,x[i]);
		Lmi=std::min(Lmi,x[i]);
		Rmx=std::max(Rmx,y[i]);
		Rmi=std::min(Rmi,y[i]);
	}
	ans=std::min(ans,(ll)(Lmx-Lmi)*(Rmx-Rmi));
}
inline void work2()
{
	if(mi==mx)return;
	for(int i=1;i<=n;++i)fz[++tot]=x[i],fz[++tot]=y[i];
	std::sort(fz+1,fz+tot+1);tot=std::unique(fz+1,fz+tot+1)-fz-1;
	int mmi=std::min(y[mx],x[mi]),mmx=y[mx]+x[mi]-mmi;
	for(int i=1;i<=n;++i)if(i!=mx&&i!=mi)mmi=std::min(mmi,x[i]),mmx=std::max(mmx,y[i]);
	int l=std::lower_bound(fz+1,fz+tot+1,mmi)-fz;
	for(int i=1;i<=n;++i)if(i!=mx&&i!=mi)G[std::lower_bound(fz+1,fz+tot+1,y[i])-fz].pb(i);
	for(int j:G[1])mmx=std::max(mmx,x[j]);
	for(int i=2;i<=l;++i)
	{
		ans=std::min(ans,(ll)(Mx-Mi)*(mmx-fz[i]));
		for(int j:G[i])mmx=std::max(mmx,x[j]);
	}
}
int main()
{
	n=in();Mx=-2e9,Mi=2e9;
	for(int i=1;i<=n;++i)
	{
		upd(x[i]=in(),i),upd(y[i]=in(),i);
		if(x[i]<y[i])std::swap(x[i],y[i]);
	}
	work1(),work2();printf("%lld\n",ans);
	return 0;
}
