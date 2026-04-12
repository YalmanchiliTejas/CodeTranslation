#include<bits/stdc++.h>
using namespace std;

long long power(long long x,long long k,long long m){
	long long ans=1;
	while(k){
		if(k&1){
			ans=(ans*x)%m;
		}
		k/=2;
		x=(x*x)%m;
	}
	return ans;
}

long long lcm(long long a,long long b,long long k,long long m){
	long long x=(a*b)/__gcd(a,b);
	// x=power(x,k,m);
	// long long ai=1;
	// while(k--)ai*=x;
	return x;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	if(t>=30)cout<<"Yes\n";
  	else cout<<"No\n";
	return 0;
}