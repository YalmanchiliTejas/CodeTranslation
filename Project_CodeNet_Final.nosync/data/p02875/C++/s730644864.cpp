#include"bits/stdc++.h"
#include<valarray>

using namespace std;

#define MAX 10000002

#define MOD 998244353


int n;

long long int k[MAX];
long long int r[MAX];

long long int ppow(long long int i,long long int j){
	long long int ret=1;
	while(j){
		if(j&1LL){
			ret*=i;
			if(ret>=MOD)ret%=MOD;
		}
		i*=i;
		if(i>=MOD)i%=MOD;
		j>>=1LL;
	}
	//cout<<"ret "<<ret<<endl;
	return ret;
}
long long int p2[MAX];
inline long long int C(int a,int b){
	long long int u=r[b]*r[a-b];
	if(u>=MOD)u%=MOD;
	u*=k[a];
	//cout<<r[b]<<" "<<r[a-b]<<" "<<k[a]<<endl;
	if(u>=MOD)u%=MOD;
	return u;
}
int main(){
	cin>>n;
	k[0]=1;
	p2[0]=1;
	for(int i=1;i<=n;i++){
		p2[i]=p2[i-1]*2LL;
		if(p2[i]>=MOD)p2[i]%=MOD;
	}
	for(int i=1;i<=n;i++){
		k[i]=k[i-1]*i;
		if(k[i]>=MOD)k[i]%=MOD;
	}
	r[n]=ppow(k[n],MOD-2);
	for(int i=n-1;i>=0;i--){
		r[i]=r[i+1]*(i+1);
		if(r[i]>=MOD)r[i]%=MOD;
	}
	int ng=n/2+1;
	long long int ans=0;
	for(int i=ng;i<=n;i++){
		//cout<<n<<" "<<i<<" "<<C(n,i)<<endl;
		long long int w=C(n,i)*p2[n-i];
		ans+=w;
		if(ans>=MOD)ans%=MOD;
	}
	ans*=2LL;
	ans%=MOD;
	long long int f=ppow(3,n);
	f+=MOD-ans;
	f%=MOD;
	ans=f;
	printf("%lld\n",ans);
	return 0;
}
