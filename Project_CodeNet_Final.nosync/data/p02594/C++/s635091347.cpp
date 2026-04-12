#include <bits/stdc++.h>
#include <math.h>

using namespace std;

template<typename T>
long long modpow(const T n,const T p,const T mod);
template<typename T>
long long modinv(const T n,const T mod);
template<typename T>
bool chmax(T &a,const T &b);
template<typename T>
bool chmin(T &a,const T &b);

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	if(n>=30) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}

template<typename T>
long long modpow(const T n,const T p,const T mod){
	if(p==0) return 1;
	if(p%2==0){
		long long a=modpow(n,p/2,mod);
		return a*a%mod;
	}
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}

template<typename T>
long long modinv(const T n,const T mod){
	return modpow(n,mod-2,mod);
}

template<typename T>
bool chmax(T &a,const T &b){
	if(a<b){
		a=b;
		return 1;
	}
	return 0;
}

template<typename T>
bool chmin(T &a,const T &b){
	if(a>b){
		a=b;
		return 1;
	}
	return 0;
}
