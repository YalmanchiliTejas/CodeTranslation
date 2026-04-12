#include<cstdio>
#include<algorithm>
const int mod=1000000007;
int N,h[110];
int pw(int a,int n){
	int b=1;
	for(;n;n>>=1)n&1?b=1ll*b*a%mod:1,a=1ll*a*a%mod;
	return b;
}
std::pair<int,int>dfs(int l,int r,int mn){
	int m=l;
	for(int i=l;i<r;i++)if(h[i]<h[m])m=i;
	int s=pw(2,h[m]-mn);
	if(r-l==1)return std::make_pair(s,s);
	if(m==l){
		std::pair<int,int>sr=dfs(m+1,r,h[m]);
		return std::make_pair((2ll*sr.first+(s-1ll)*sr.second)%mod,1ll*s*sr.second%mod);
	}
	if(m==r-1){
		std::pair<int,int>sl=dfs(l,m,h[m]);
		return std::make_pair((2ll*sl.first+(s-1ll)*sl.second)%mod,1ll*s*sl.second%mod);
	}
	std::pair<int,int>sl=dfs(l,m,h[m]),sr=dfs(m+1,r,h[m]);
	return std::make_pair(
		(4ll*sl.first%mod*sr.first+(s-1ll)*sl.second%mod*sr.second)%mod,
		1ll*s*sl.second%mod*sr.second%mod
	);
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",h+i),--h[i];
	printf("%d\n",dfs(0,N,0).first*2%mod);
}