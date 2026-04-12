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
	long long n,x,m;
	cin>>n>>x>>m;
	long long ans=0;
	long long roop=0;
	long long inroop=0;
	long long cnt=0;
	vector<long long> num;
	map<long long,long long> zisyo;

	for(long long i=0;i<n;i++){
		zisyo[x]++;
		if(zisyo[x]==2){
			roop=1;
		}
		if(zisyo[x]==3){
			n-=i;
			ans+=inroop*(n/cnt)+inroop;
			for(long long j=0;j<n%cnt;j++){
				ans+=num.at(j);
			}
			break;
		}

		if(roop==0){
			ans+=x;
		}else{
			inroop+=x;
			num.push_back(x);
			cnt++;
		}
		x*=x;
		x%=m;
	}

	cout<<ans<<endl;

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
