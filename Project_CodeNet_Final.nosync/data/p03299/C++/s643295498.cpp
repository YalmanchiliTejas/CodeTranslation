#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=105,mo=1e9+7;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
inline int SS(int x){return poww(2,x+1)-1;}
inline int S(int l,int r){return (SS(r)+mo-SS(l))%mo;}
int n,h[N],hh[N],h2[N],i,j,k,f[N][N],nn,ans;
inline void work(int i,int z,int x){
	for(;i<=h2[z];++i)
		f[z][i]=(f[z][i]+1ll*x*(hh[i]>1?S(h[z]-hh[i]-1,h[z]-max(1,hh[i-1])-1):0))%mo;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",h+i),hh[i]=h[i];
	sort(hh+1,hh+n+1);nn=unique(hh+1,hh+n+1)-hh-1;
	for(i=1;i<=n;++i)h2[i]=lower_bound(hh+1,hh+nn+1,h[i])-hh;
	f[1][0]=2;work(1,1,2);
	for(i=1;i<n;++i){
		for(j=1;j<=h2[i] && j<=h2[i+1];++j)f[i+1][j]=1ll*(h2[i]<h2[i+1]?poww(2,h[i+1]-h[i]):1)*f[i][j]%mo;
		work(h2[i]+1,i+1,(h2[i]==1?2ll:2ll)*f[i][0]%mo);
		for(j=0;j<=h2[i];++j)if(!j || j>h2[i+1])f[i+1][0]=(f[i+1][0]+2ll*f[i][j])%mo;
	}
	for(i=0;i<=h2[n];++i)ans=(ans+f[n][i])%mo;
	printf("%d\n",ans);
	return 0;
}