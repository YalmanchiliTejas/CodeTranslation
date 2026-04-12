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
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double INF=1e+10;
const double PI=acos(-1.0);
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
typedef unsigned long long wolf;
int S[510];
int T[510];
wolf U[510];
wolf V[510];
wolf ans[510][510];
wolf ori[510][510];
int tmp[510][510];
char row[510];
char col[510];
int n;
bool chk(int a){
	wolf mask=((wolf)1)<<a;

	for(int i=0;i<n;i++){
		int AND=1;
		int OR=0;
		for(int j=0;j<n;j++){
			if(ans[i][j]&mask)OR=1;
			else AND=0;
		}
		if(row[i]=='A'&&OR==1)return false;
		if(row[i]=='B'&&OR==0)return false;
		if(row[i]=='C'&&AND==1)return false;
		if(row[i]=='D'&&AND==0)return false;
	}
	for(int i=0;i<n;i++){
		int AND=1;
		int OR=0;
		for(int j=0;j<n;j++){
			if(ans[j][i]&mask)OR=1;
			else AND=0;
		}
		if(col[i]=='A'&&OR==1)return false;
		if(col[i]=='B'&&OR==0)return false;
		if(col[i]=='C'&&AND==1)return false;
		if(col[i]=='D'&&AND==0)return false;
	}
	return true;
}
int main(){
	int a;scanf("%d",&a);n=a;
	for(int i=0;i<a;i++){
		scanf("%d",S+i);
	}
	for(int i=0;i<a;i++){
		scanf("%d",T+i);
	}
	for(int i=0;i<a;i++){
		scanf("%llu",U+i);
	}
	for(int i=0;i<a;i++){
		scanf("%llu",V+i);
	}
	bool ok=true;
	for(int i=0;i<64;i++){
		wolf mask=((wolf)1)<<i;
		for(int j=0;j<a;j++){
			row[j]='A';
			if(S[j]==0){
				row[j]+=2;
			}
			if(U[j]&mask){
				row[j]++;
			}
		}
		for(int j=0;j<a;j++){
			col[j]='A';
			if(T[j]==0){
				col[j]+=2;
			}
			if(V[j]&mask){
				col[j]++;
			}
		}
		int rA=0;
		int rD=0;
		int cA=0;
		int cD=0;
		vector<int>rB;
		vector<int>cB;
		for(int j=0;j<a;j++){
			if(row[j]=='A')rA++;
			else if(row[j]=='D'){
				rD++;
				for(int k=0;k<a;k++){
					ans[j][k]|=mask;
				}
			}else rB.push_back(j);
		}
		for(int j=0;j<a;j++){
			if(col[j]=='A')cA++;
			else if(col[j]=='D'){
				cD++;
				for(int k=0;k<a;k++){
					ans[k][j]|=mask;
				}
			}
			else cB.push_back(j);
		}
		// printf("%s %s\n",row,col);
		if(rA&&cD){ok=false;break;}
		if(rD&&cA){ok=false;break;}
		
		if(min(rB.size(),cB.size())>1){
			for(int j=0;j<max(rB.size(),cB.size());j++){
				ans[rB[j%rB.size()]][cB[j%cB.size()]]|=mask;
			}
			continue;
		}
		if(rB.size()==0||cB.size()==0){
			if(!chk(i)){
				ok=false;break;
			}
			continue;
		}
		
		if(rB.size()==1){
			for(int j=0;j<a;j++)for(int k=0;k<a;k++)ori[j][k]=ans[j][k];
			bool OK=false;
			for(int I=0;I<4;I++){
				for(int j=0;j<a;j++)for(int k=0;k<a;k++)ans[j][k]=ori[j][k];
				int fB=-1;
				int fC=-1;
				for(int j=0;j<cB.size();j++){
					if(col[cB[j]]=='B'){
						if(I&1)ans[rB[0]][cB[j]]|=mask;
						fB=cB[j];
					}else{
						if(I&2)ans[rB[0]][cB[j]]|=mask;
						fC=cB[j];
					}
				}
				if(chk(i)){
					OK=true;break;
				}
				if(~fB){
					ans[rB[0]][fB]^=mask;
				}
				if(chk(i)){
					OK=true;break;
				}
				if(~fB){
					ans[rB[0]][fB]^=mask;
				}
				if(~fC){
					ans[rB[0]][fC]^=mask;
				}
				if(chk(i)){
					OK=true;break;
				}
			}
			if(OK)continue;
			ok=false;break;
		}else{
			for(int j=0;j<a;j++)for(int k=0;k<a;k++)ori[j][k]=ans[j][k];
			bool OK=false;
			for(int I=0;I<4;I++){
				for(int j=0;j<a;j++)for(int k=0;k<a;k++)ans[j][k]=ori[j][k];
				int fB=-1;
				int fC=-1;
				for(int j=0;j<rB.size();j++){
					if(row[rB[j]]=='B'){
						if(I&1)ans[rB[j]][cB[0]]|=mask;
						fB=rB[j];
					}else{
						if(I&2)ans[rB[j]][cB[0]]|=mask;
						fC=rB[j];
					}
				}
				if(chk(i)){
					OK=true;break;
				}
				if(~fB){
					ans[fB][cB[0]]^=mask;
				}
				if(chk(i)){
					OK=true;break;
				}
				if(~fB){
					ans[fB][cB[0]]^=mask;
				}
				if(~fC){
					ans[fC][cB[0]]^=mask;
				}
				if(chk(i)){
					OK=true;break;
				}
			}
			if(OK)continue;
			ok=false;break;
		}
	}
	if(!ok){
		printf("-1\n");return 0;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(j)printf(" ");
			printf("%llu",ans[i][j]);
		}
		printf("\n");
	}
}
