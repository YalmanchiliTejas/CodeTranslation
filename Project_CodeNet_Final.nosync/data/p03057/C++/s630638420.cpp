#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
char S[200010];
int f[200010],sf[200010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),all=0;
	scanf("%s",S+1);
	int L=1145141;
	for(int l=1,r;l<=m;l=r+1){
		r=l;if(S[l]!=S[1])continue;
		while(r<m&&S[r+1]==S[r])++r;
		if(l==1&&r==m)all=1;
		if(((r-l+1&1)||l==1)&&r<m)cnk(L,r-l+2);
	}
	if(all){
		static int f[200010][2];
		int ans=0;
		for(int fir=0;fir<2;++fir){
			memset(f,0,sizeof f);
			f[1][fir]=1;
			for(int i=1;i<=n;++i){
				inc(f[i+1][0],f[i][1]);
				inc(f[i+1][1],f[i][0]);
				inc(f[i+1][1],f[i][1]);
			}
			if(fir)inc(ans,f[n][0]);
			inc(ans,f[n][1]);
		}
		printf("%d\n",ans);
		return 0;
	}
	if(L&1)++L;
	f[1]=sf[1]=1;
	for(int i=2;i<=n;++i)f[i]=(sf[i-2]-(i-L-2<0?0:sf[i-L-2])+mod)%mod,sf[i]=(f[i]+sf[i-2])%mod;
	int ans=0;
	for(int i=n-1;n-i<L&&i>=0;i-=2)
		inc(ans,1ll*(n-i+1)*f[i]%mod);
	printf("%d\n",ans);
	return 0;
}
