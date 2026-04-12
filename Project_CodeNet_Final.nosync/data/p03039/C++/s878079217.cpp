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
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
long long fact[210000];
long long finv[210000];
long long inv[210000];
long long C(int a,int b){
	if(a<b||b<0)return 0;
	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<210000;i++)
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	for(int i=1;i<210000;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	long long ret=0;
	for(int i=1;i<a;i++){
		long long ks=(long long)b*b*(a-i)%mod*i%mod;
		ret=(ret+ks)%mod;
	}
	for(int i=1;i<b;i++){
		long long ks=(long long)a*a*(b-i)%mod*i%mod;
		ret=(ret+ks)%mod;
	}
	ret=ret*C(a*b-2,c-2)%mod;
	printf("%lld\n",ret);
}
