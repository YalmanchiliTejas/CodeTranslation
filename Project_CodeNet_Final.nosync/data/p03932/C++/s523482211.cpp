// #pragma GCC target("avx2")  // CPU 処理並列化
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
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
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
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
// ここから編集しろ
int p[210][210];
int dp[410][210][210];

int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)for(int j=0;j<b;j++){
		scanf("%d",&p[i][j]);
	}
	dp[0][0][0]=p[0][0];
	for(int i=0;i<a+b;i++){
		for(int j=0;j<max(a,b);j++){
			int X1=j;
			int Y1=i-j;
			if(X1>=a||Y1<0||Y1>=b)continue;
			for(int k=0;k<max(a,b);k++){
				int X2=k;
				int Y2=i-k;
				if(X2>=a||Y2<0||Y2>=b)continue;

				if(X1+1<a&&X2+1<a){
					int to=dp[i][j][k]+p[X1+1][Y1];
					if(X1!=X2)to+=p[X2+1][Y2];
					dp[i+1][X1+1][X2+1]=max(dp[i+1][X1+1][X2+1],to);
				}
				if(X1+1<a&&Y2+1<b){
					int to=dp[i][j][k]+p[X1+1][Y1];
					if(X1+1!=X2)to+=p[X2][Y2+1];
					dp[i+1][X1+1][X2]=max(dp[i+1][X1+1][X2],to);
				}
				if(Y1+1<b&&X2+1<a){
					int to=dp[i][j][k]+p[X1][Y1+1];
					if(X1!=X2+1)to+=p[X2+1][Y2];
					dp[i+1][X1][X2+1]=max(dp[i+1][X1][X2+1],to);
				}
				if(Y1+1<b&&Y2+1<b){
					int to=dp[i][j][k]+p[X1][Y1+1];
					if(X1!=X2)to+=p[X2][Y2+1];
					dp[i+1][X1][X2]=max(dp[i+1][X1][X2],to);
				}
				
			}
		}
	}
	printf("%d\n",dp[a+b-2][a-1][a-1]);
}
