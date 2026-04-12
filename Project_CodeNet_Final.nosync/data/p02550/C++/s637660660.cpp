#include<bits/stdc++.h>
using namespace std;

template <typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c-48);c=getchar();}
	return x*f;
}

#define lint long long int
#define ulint unsigned lint
#define readint read<int>()
#define readlint read<lint>()
const int inf=1e9+1e7,MAXN=1e5+1e1;

lint dp[MAXN],t[MAXN],tmp=0,ans=0,n,x,y,m,cnt=0;

int main(void){

	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);

	scanf("%lld%lld%lld",&n,&x,&m);
	t[x]=1,tmp=x,dp[x]=x,y=x*x%m,++cnt;
	while(!t[y] && cnt<n){
		t[y]=cnt+1,tmp+=y,dp[y]=dp[x]+y,x=y,y=x*x%m,++cnt;
	}
	ans=tmp;
	if(cnt==n){
		printf("%lld\n",ans);
		return 0;
	}
	n-=cnt,ans+=(n/(cnt-t[y]+1))*(tmp-dp[y]+y),n%=(cnt-t[y]+1),cnt=0;
	while(cnt<n){
		++cnt,ans+=y,x=y,y=x*x%m;
	}
	printf("%lld\n",ans);

	return 0;
}