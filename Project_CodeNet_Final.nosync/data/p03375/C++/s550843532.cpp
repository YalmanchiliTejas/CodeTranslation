#include<cstdio>

using int64=long long;
using uchar=unsigned char;

constexpr int maxn(3000);

inline int io(){
	static int _;
	return scanf("%d",&_),_;
}

int inv[maxn+1],
	C[maxn+1],
	S[maxn+1][maxn+1];

int main(){
	const int n=io(),p=io();

	const auto inc=[p](auto&x,const auto&y){x+=y;(p<=x)&&(x-=p);};
	const auto pls=[p](const auto&x,const auto&y){return x+y<p?x+y:(x+y-p);};

	inv[1]=1;
	for(int i=2;i!=n;++i)
		inv[i]=(int64)inv[p%i]*(p-p/i)%p;

	C[0]=C[n]=1;
	for(int i=1;i!=n;++i)
		C[i]=(int64)C[i-1]*inv[i]%p*(n-i+1)%p;

	S[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=(S[i][0]=1);j<=i;++j)
			S[i][j]=(S[i-1][j-1]+(int64)S[i-1][j]*(j+1))%p;

	int64 ans=0;
	for(int i=n,pw=1,pw2=2;~i;--i,inc(pw,pw),pw2=(int64)pw2*pw2%p){
		int64 t=0;
		for(int j=0,pw3=1;j<=i;++j,pw3=(int64)pw3*pw%p)
			t+=(int64)pw3*S[i][j]%p;
		(i&1)?(ans-=t%p*pw2%p*C[i]%p):(ans+=t%p*pw2%p*C[i]%p);
	}

	printf("%d",pls(ans%p,p));

	return 0;
}
