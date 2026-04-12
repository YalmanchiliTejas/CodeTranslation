#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

int n,a[N],foo[N],bar[N];

int fp(int x){
	return 1ll*foo[x%N]*bar[x/N]%mod;
}

pair<int,int>solve(int l,int r,int h){
	int mn=1<<30,cnt=0,x=1,y=1;
	for(int i=l;i<=r;++i)
		if(a[i]<mn)mn=a[i],cnt=1;
		else if(a[i]==mn)++cnt;
	if(cnt==r-l+1)
		x=fp(r-l+1)-2,y=fp(mn-h);
	else{
		int z=r-l+1;
		for(int i=l,j=0;i<=r;++i){
			if(!j&&a[i]>mn)j=i;
			if(j&&(i==r||a[i+1]==mn)){
				auto res=solve(j,i,mn);
				x=(res.first+2ll*res.second)*x%mod;
				y=1ll*res.second*y%mod;
				z-=i-j+1;j=0;
			}
		}
		x=(x+mod-y)%mod;
		x=(1ll*x*fp(z)+1ll*y*(fp(z)-2))%mod;
		y=1ll*y*fp(mn-h)%mod;
	}
	return make_pair(x,y);
}

int main(){
	foo[0]=1;foo[1]=2;
	for(int i=2;i<N;++i)foo[i]=1ll*foo[i-1]*foo[1]%mod;
	bar[0]=1;bar[1]=(foo[N-1]<<1)%mod;
	for(int i=2;i<N;++i)bar[i]=1ll*bar[i-1]*bar[1]%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	auto ans=solve(1,n,0);
	printf("%d\n",(ans.first+ans.second)%mod);
	return 0;
}
