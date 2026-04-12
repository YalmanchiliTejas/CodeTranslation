#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
	ll a,b,x;
	cin>>a>>b>>x;
	const int mod=1000000007;
	ll ans=x;
	if(x>=a){
		ans+=((x-a)/(a-b)+1)%mod*(b%mod)%mod;
	}
	ans%=mod;
	cout<<ans<<endl;
    return 0;
}

