#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1000000007;

int N;
ll A[200000];
ll T;


ll pw(ll x,int y){
	ll a=1;
	while(y){
		if(y&1){
			a*=x;
			a%=mod;
		}
		x=x*x%mod;
		y/=2;
	}
	return a;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N;i++){
		T+=A[i];
		T%=mod;
	}
	T*=T;
	T%=mod;
	for(int i=0;i<N;i++){
		T-=A[i]*A[i]%mod;
		T+=mod;
		T%=mod;
	}
	T*=pw(2,mod-2);
	T%=mod;
	cout<<T<<endl;
}
