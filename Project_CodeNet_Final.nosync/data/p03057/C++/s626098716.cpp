#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005,INF=0X3F3F3F3F,P=1e9+7;
int n,m,f[N];
char s[N];
void sol1(){
	f[1]=1;
	rep(i,2,n+1)f[i]=(f[i-1]+f[i-2])%P;
	printf("%d\n",(f[n-1]+f[n+1])%P);
}
void sol2(int n,int lim){
	D("n=%d lim=%d\n",n,lim);
	int cur=0;
	for(int i=1;i<=n;++i){
		if(i>lim+1)cur=(cur-f[i-lim-1]+P)%P;
		f[i]=(cur+(i<=lim?i:0))%P;
		cur=(cur+f[i])%P;
	}
	printf("%lld\n",2LL*f[n]%P);
}
int main(){
	scanf("%d%d%s",&n,&m,s);
	if(s[0]=='B'){
		rep(i,0,m-1)s[i]=(s[i]=='R'?'B':'R');
	}
	if(count(s,s+m,s[0])==m){
		sol1();
		return 0;
	}
	if(n&1)puts("0"),exit(0);
	bool fir=1;
	int mn=INF;
	for(int i=0,j;i<m;i=j){
		j=i+1;
		while(j<m&&s[j]==s[i])++j;
		if(j>=m)break;
		if(s[i]=='R'&&(fir||(j-i)%2))mn=min(mn,j-i),fir=0;
	}
	sol2(n/2,mn/2+1);
	return 0;
}