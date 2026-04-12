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
	inline long long Comb(int a,int b){
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
int p[3100];
int S;
int N;
long long ret=0;
long long dpL[1600][3100];
long long dpR[1600][3100];
long long tl[3100];
long long tr[3100];
void calc(int a,int b){
	if(a>b)return;
	if(a==b){
		if(p[a]==S)ret+=(a+1)*(N-a);
		return ;
	}
	int M=(a+b)/2;
	calc(a,M);
	calc(M+1,b);
	int sl=M-a+1;
	int sr=b-M;
	for(int i=0;i<=sl;i++)for(int j=0;j<=S;j++)dpL[i][j]=0;
	for(int i=0;i<=sr;i++)for(int j=0;j<=S;j++)dpR[i][j]=0;
	dpL[0][0]=1;
	dpR[0][0]=1;
	for(int i=0;i<=S;i++)tl[i]=tr[i]=0;
	for(int i=0;i<sl;i++){
		for(int j=0;j<=S;j++){
			tl[j]+=dpL[i][j];
			dpL[i+1][j]=(dpL[i+1][j]+dpL[i][j])%mod;
			if(j+p[M-i]<=S)dpL[i+1][j+p[M-i]]=(dpL[i+1][j+p[M-i]]+dpL[i][j])%mod;
		}
	}
	for(int i=0;i<sr;i++){
		for(int j=0;j<=S;j++){
			tr[j]+=dpR[i][j];
			dpR[i+1][j]=(dpR[i+1][j]+dpR[i][j])%mod;
			if(j+p[M+1+i]<=S)dpR[i+1][j+p[M+1+i]]=(dpR[i+1][j+p[M+1+i]]+dpR[i][j])%mod;
		}
	}
	for(int i=0;i<=S;i++){
		tl[i]+=dpL[sl][i]*(a+1)%mod;
		tr[i]+=dpR[sr][i]*(N-b)%mod;
	}
	for(int i=0;i<=S;i++){
		tl[i]%=mod;
		tr[i]%=mod;
	}
	long long tmp=0;
	for(int i=1;i<S;i++){
		tmp+=tl[i]*tr[S-i]%mod;
	}
	// printf("%d %d: %lld\n",a,b,tmp);
	ret+=tmp;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	N=a;
	S=b;
	for(int i=0;i<a;i++)scanf("%d",p+i);
	calc(0,a-1);
	ret%=mod;
	printf("%lld\n",ret);
}