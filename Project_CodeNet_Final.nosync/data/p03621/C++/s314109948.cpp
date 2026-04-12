#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10010
#define ll long long
#define mod 998244353
#define g 3
using namespace std;

int nn, n, m, inv[N], INV, R[N*4], a[N*4], b[N*4], c[N*4], n1, L, ans;
char s1[N], s2[N];

inline int pow(int y, int x){
	int s=1, t=y;
	while(x){if(x&1)s=(ll)s*t%mod; t=(ll)t*t%mod; x>>=1;}
	return s;
}

inline void ntt(int *a, int f){
	for(int i=0; i<n1; i++)if(i<R[i])swap(a[i], a[R[i]]);
	for(int i=1; i<n1; i<<=1){
		int wn=pow(g, (mod-1)/(i*2)); if(f==-1)wn=pow(wn, mod-2);
		for(int j=0; j<n1; j+=i*2){
			int w=1;
			for(int k=0; k<i; k++){
				int x=a[j+k], y=(ll)w*a[j+k+i]%mod;
				a[j+k]=x+y; if(a[j+k]>=mod)a[j+k]-=mod;
				a[j+k+i]=x-y; if(a[j+k+i]<0)a[j+k+i]+=mod;
				w=(ll)w*wn%mod;
			}
		}
	}
	if(f==-1)for(int i=0; i<n1; i++)a[i]=(ll)a[i]*INV%mod;
}

inline void mul_poly(int *a, int *b){
	memcpy(c, b, sizeof(c));
	n1=n+1; L=0; while((1<<L)<n1*2)L++; n1=1<<L;
	for(int i=0; i<n1; i++)R[i]=(R[i/2]/2)|((i&1)<<(L-1));
	INV=pow(n1, mod-2);
	ntt(a, 1); ntt(c, 1);
	for(int i=0; i<n1; i++)a[i]=(ll)a[i]*c[i]%mod;
	ntt(a, -1);
	for(int i=n+1; i<n1; i++)a[i]=0;
}
inline void pow_poly(int *a, int *b, int x){
	while(x){
		if(x&1)mul_poly(a, b);
		mul_poly(b, b);
		x>>=1;
	}
}

int main(){
	scanf("%s%s", s1+1, s2+1); nn=strlen(s1+1);
	m=0; for(int i=1; i<=nn; i++)if(s1[i]=='1'&&s2[i]=='0')m++;
	n=0; for(int i=1; i<=nn; i++)if(s1[i]=='1'&&s2[i]=='1')n++;
	inv[0]=inv[1]=1; for(int i=2; i<=n+1; i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1; i<=n+1; i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
	memset(a, 0, sizeof(a)); a[0]=1;
	memset(b, 0, sizeof(b)); for(int i=0; i<=n; i++)b[i]=inv[i+1];
	pow_poly(a, b, m);
	ans=0; for(int i=0; i<=n; i++)ans=(ans+a[i])%mod;
	for(int i=1; i<=m; i++)ans=(ll)ans*i%mod;
	for(int i=1; i<=n; i++)ans=(ll)ans*i%mod;
	for(int i=1; i<=n+m; i++)ans=(ll)ans*i%mod;
	printf("%d", ans);
	return 0;
}