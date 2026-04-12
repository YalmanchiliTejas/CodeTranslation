// #pragma GCC target("avx")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
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
#include<complex>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
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
		if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// ここから編集しろ
char S[210000];
char T[210000];
string ret="~";
char tmp[210000];
int main(){
	int a;scanf("%d",&a);
	scanf("%s%s",S,T);
	int s=strlen(S);
	int t=strlen(T);
	int fi=-1;
	int la=-1;
	for(int i=0;s*i<=a;i++){
		if((a-i*s)%t==0){
			la=i;
			if(fi==-1)fi=i;
		}
	}
	int ind=0;
	for(int i=0;i<fi;i++){
		for(int j=0;j<s;j++)tmp[ind++]=S[j];
	}
	for(int i=0;i<(a-s*fi)/t;i++){
		for(int j=0;j<t;j++)tmp[ind++]=T[j];
	}
	string str=tmp;
	ret=min(ret,str);
	ind=0;
	for(int i=0;i<(a-s*fi)/t;i++){
		for(int j=0;j<t;j++)tmp[ind++]=T[j];
	}
	for(int i=0;i<fi;i++){
		for(int j=0;j<s;j++)tmp[ind++]=S[j];
	}
	str=tmp;
	ret=min(ret,str);
	ind=0;
	for(int i=0;i<(a-s*la)/t;i++){
		for(int j=0;j<t;j++)tmp[ind++]=T[j];
	}
	for(int i=0;i<la;i++){
		for(int j=0;j<s;j++)tmp[ind++]=S[j];
	}
	str=tmp;
	ret=min(ret,str);
	ind=0;
	for(int i=0;i<la;i++){
		for(int j=0;j<s;j++)tmp[ind++]=S[j];
	}
	for(int i=0;i<(a-s*la)/t;i++){
		for(int j=0;j<t;j++)tmp[ind++]=T[j];
	}
	
	str=tmp;
	ret=min(ret,str);
	printf("%s\n",ret.c_str());
}