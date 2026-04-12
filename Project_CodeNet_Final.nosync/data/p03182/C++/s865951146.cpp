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
const int UF_SIZE = 210000;
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
long long dp[210000];
long long segtree[524288];
long long query(int a,int b,int c,int d,int e,long long f){
	if(d<a||b<c){
		return inf;
	}
	if(c<=a&&b<=d){
		return f+segtree[e];
	}
	long long l=query(a,(a+b)/2,c,d,e*2,f+segtree[e]);
	long long r=query((a+b)/2+1,b,c,d,e*2+1,f+segtree[e]);
	return min(l,r);
}
void add(int a,int b,int c,int d,int e,long long f){
	if(d<a||b<c){
		return;
	}
	if(c<=a&&b<=d){
		segtree[e]+=f;
	}else{
		add(a,(a+b)/2,c,d,e*2,f);
		add((a+b)/2+1,b,c,d,e*2+1,f);
		if(min(segtree[e*2],segtree[e*2+1])!=0){
			long long m=min(segtree[e*2],segtree[e*2+1]);
			segtree[e]+=m;
			segtree[e*2]-=m;
			segtree[e*2+1]-=m;
		}
	}
}
vector<pair<int,int> >g[210000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	long long sum=0;
	for(int i=0;i<b;i++){
		int s,t,u;scanf("%d%d%d",&s,&t,&u);
		sum+=u;
		g[t].push_back(make_pair(s,u));
	}

	for(int i=1;i<=a;i++){
		for(int j=0;j<g[i-1].size();j++){
			add(0,262143,0,g[i-1][j].first-1,1,g[i-1][j].second);
		}
		long long tmp=query(0,262143,0,i-1,1,0);
		dp[i]=tmp;
		// printf("%d: %lld\n",i,dp[i]);
		add(0,262143,i,i,1,dp[i]);
	}
	for(int j=0;j<g[a].size();j++){
		add(0,262143,0,g[a][j].first-1,1,g[a][j].second);
	}
	long long ret=sum-query(0,262143,0,a,1,0);

	printf("%lld\n",ret);
}
