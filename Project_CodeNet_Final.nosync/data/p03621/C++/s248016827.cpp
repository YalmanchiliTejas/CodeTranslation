#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
const int mod=998244353;
const int N=10001;
int f[N], F[N], n, a, b;
char s1[N], s2[N];
void inc(int &a,int b){ (a+=b)%=mod; }
int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*f[n]*F[m]%mod*F[n-m]%mod;
}
int mi(int a,int b){
	int s=1;
	for(;b;b>>=1,a=1LL*a*a%mod)
		if(b&1)s=1LL*s*a%mod;
	return s;
}
int A[N], ans;
int main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	f[0] = 1;
	ref(i,1,n)f[i] = 1LL*f[i-1]*i%mod;
	F[n] = mi(f[n], mod-2);
	def(i,n,1)F[i-1] = 1LL*F[i]*i%mod;
	ref(i,1,n)if(s1[i]=='1'&&s2[i]=='1')b++;else
		if(s1[i]=='1')a++;
	A[0]=1;
	def(i,a,1){
		ref(j,0,a+b)if(A[j])A[j+1]=(1LL*A[j]*i+A[j+1])%mod;
		def(j,a+b,1)A[j]=A[j-1];A[0]=0;
	}
	ref(i,a,a+b)A[i]=1LL*A[i]*f[a]%mod*f[b]%mod*F[b-(i-a)]%mod;
	ref(i,a,a+b)inc(ans,1LL*A[i]*f[a+b-i]%mod*f[a+b-i]%mod*C(a+b,i)%mod);
	cout<<1LL*ans*f[a]%mod<<endl;
}