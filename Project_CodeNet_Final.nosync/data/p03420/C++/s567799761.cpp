#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n, k; cin>>n>>k;
	ll ret=0;
	if(k==0){
		cout<<n*n<<'\n';
		return 0;
	}
	for(ll b=k+1;b<=n;b++){
		ret+= (n/b) * (b-k);
		ret+= max(0LL, n%b + 1 - k);
	}
	cout<<ret<<'\n';
	return 0;
}