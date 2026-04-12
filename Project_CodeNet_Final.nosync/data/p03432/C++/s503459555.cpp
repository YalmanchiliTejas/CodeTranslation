// #pragma GCC target("avx")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
// #define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
// #define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<complex>
using namespace std;
const long long mod=998244353;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double INF=1e+10;
const long double PI=acos(-1.0);
const int C_SIZE = 3100000;
const int UF_SIZE = 3100000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	long long Comb(int a,int b){
	 	if(a<b||b<0)return 0;
	 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
	}
	void init_C(int n){
		fact[0]=finv[0]=inv[1]=1;
		for(int i=2;i<n;i++){
			inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
		}
		for(int i=1;i<n;i++){
			fact[i]=fact[i-1]*i%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	long long pw(long long a,long long b){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return ret;
	}
	long long pw_mod(long long a,long long b,long long M){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%M;
			a=a*a%M;
			b/=2;
		}
		return ret;
	}
	int pw_mod_int(int a,int b,int M){
		if(a<0)return 0;
		if(b<0)return 0;
		int ret=1;
		while(b){
			if(b%2)ret=(long long)ret*a%M;
			a=(long long)a*a%M;
			b/=2;
		}
		return ret;
	}
	int ABS(int a){return max(a,-a);}
	long long ABS(long long a){return max(a,-a);}
	double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
	int UF[UF_SIZE];
	void init_UF(int n){
		for(int i=0;i<n;i++)UF[i]=-1;
	}
	int FIND(int a){
		if(UF[a]<0)return a;
		return UF[a]=FIND(UF[a]);
	}
	void UNION(int a,int b){
		a=FIND(a);b=FIND(b);if(a==b)return;
		// if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// ここから編集しろ
namespace NTT_998244353{
	long long extgcd(long long a,long long b,long long&x,long long&y){
		for(long long u=y=1,v=x=0;a;){
			long long q=b/a;swap(x-=q*u,u);swap(y-=q*v,v);swap(b-=q*a,a);
		}
		return b;
	}
	long long mod_inv(long long a,long long m){
		long long x,y;
		extgcd(a,m,x,y);
		return (m+x%m)%m;
	}
	long long mod_pow(long long a,long long b,long long m){
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%m;
			b/=2;
			a=a*a%m;
		}
		return ret;
	}
	template<int mod,int primitive_root> class NTT{
		public:
		int get_mod()const{return mod;}
		void _ntt(vector<int>&a,int sign){
			const int n=a.size();
			const int g=3;
			int h=(int)mod_pow(g,(mod-1)/n,mod);
			if(sign==-1)h=(int)mod_inv(h,mod);
			int i=0;
			for(int j=1;j<n-1;j++){
				for(int k=n>>1;k>(i^=k);k>>=1);
				if(j<i)swap(a[i],a[j]);
			}
			for(int m=1;m<n;m*=2){
				const int m2=2*m;
				const int base=mod_pow(h,n/m2,mod);
				int w=1;
				for(int x=0;x<m;x++){
					for(int s=x;s<n;s+=m2){
						const int u=a[s];
						const int d=(long long)a[s+m]*w%mod;
						a[s]+=d;
						if(a[s]>=mod)a[s]-=mod;
						a[s+m]=u-d;
						if(a[s+m]<0)a[s+m]+=mod;
					}
					w=(long long)w*base%mod;
				}
			}
			for(int i=0;i<a.size();i++)if(a[i]<0)a[i]+=mod;
		}
		void ntt(vector<int>&input){
			_ntt(input,1);
		}
		void intt(vector<int>&input){
			_ntt(input,-1);
			const int n_inv=mod_inv(input.size(),mod);
			for(int i=0;i<input.size();i++)input[i]=(long long)input[i]*n_inv%mod;
		}
		vector<int>convolution(const vector<int>&a,const vector<int>&b){
			int ntt_size=1;
			while(ntt_size<a.size()+b.size())ntt_size*=2;
			vector<int>_a=a,_b=b;
			_a.resize(ntt_size);
			_b.resize(ntt_size);
			ntt(_a);
			ntt(_b);
			for(int i=0;i<ntt_size;i++){
				_a[i]=(long long)_a[i]*_b[i]%mod;
			}
			intt(_a);
			return _a;
		}
	};
	typedef NTT<998244353,3> NTT_1;
	vector<int> mod_convolution(vector<int>a,vector<int>b,int mod){
		NTT_1 ntt1;
		vector<int>x=ntt1.convolution(a,b);
		return x;
	}
}
long long dp[210][8100];

int main(){
	int a,b;scanf("%d%d",&a,&b);
	init_C(210000);
	dp[0][0]=1;
	for(int i=0;i<b;i++){
		vector<int>A(a+1);
		vector<int>B(a+1);
		for(int j=0;j<=a;j++){
			A[j]=dp[i][j]*finv[j]%mod;
			if(j)B[j]=finv[j+2];
		}
		vector<int>C=NTT_998244353::mod_convolution(A,B,(int)mod);
		for(int j=0;j<=a;j++){
			dp[i+1][j]=C[j];
		}
		for(int j=0;j<=a;j++){
			dp[i+1][j]=dp[i+1][j]*fact[j+2]%mod;
		}
		for(int j=0;j<=a;j++){
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(Comb(j+1,2)+1))%mod;
		}
	}
	long long ret=0;

	for(int i=0;i<=a;i++)ret+=dp[b][i]*Comb(a,i)%mod;
	ret%=mod;
	printf("%lld\n",ret);
}