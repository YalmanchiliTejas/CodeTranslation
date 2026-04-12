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
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 210000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
// long long C(int a,int b){
// 	if(a<b||b<0)return 0;
// 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
// }
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
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
// ここから編集しろ
char in[110][110];
int r[110];
int c[110];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",in[i]);
	for(int i=0;i<a;i++)for(int j=0;j<b;j++){
		if(in[i][j]=='#')r[i]=c[j]=1;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)if(r[i]&&c[j])printf("%c",in[i][j]);
		printf("\n");
	}
}