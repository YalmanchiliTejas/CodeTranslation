#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=3005;
int n;
LL mod;
LL fact[Maxn],ivf[Maxn];
LL qp(LL x,LL p){
	LL ret=1;
	while (p){
		if (p&1) ret=ret*x%mod;
		p>>=1;
		x=x*x%mod;
	}
	return ret;
}
LL Qp(LL x,LL p){
	LL ret=1;
	while (p){
		if (p&1) ret=ret*x%(mod-1);
		p>>=1;
		x=x*x%(mod-1);
	}
	return ret;
} 
LL inv(LL x){
	return qp(x,mod-2);
}
LL C(LL x,LL y){
	return fact[x]*ivf[y]%mod*ivf[x-y]%mod;
}
LL H[Maxn][Maxn];
void _init(){
	fact[0]=1;//cerr<<123<<endl;
	for (int i=1;i<Maxn;i++) fact[i]=fact[i-1]*i%mod;
	for (int i=0;i<Maxn;i++) ivf[i]=inv(fact[i]);
	H[0][0]=1;//cerr<<123<<endl;
	for (int i=1;i<Maxn;i++){
		H[i][0]=1;
		for (int j=1;j<=i;j++){
			H[i][j]=(H[i-1][j-1]+H[i-1][j]*(j+1))%mod;
		}
	}
}
int main(){
	scanf("%d %lld",&n,&mod);
	_init();
	
	LL ans=0;
	for (int i=0;i<=n;i++){
		LL coef=C(n,i);
		LL t=Qp(2,n-i);
		t=qp(2,t);
		coef=coef*t%mod;
		if (i&1) coef=mod-coef;
		LL cur=0;
		for (int k=0;k<=i;k++){
			cur+=qp(2,(n-i)*k)*H[i][k];
			cur%=mod;
		}
		ans+=coef*cur;
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}