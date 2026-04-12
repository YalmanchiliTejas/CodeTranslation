#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn=1e6+10;
#define p 1000000007
int main(){
	fast;
	ll n,s=0,ans=0; cin>>n;
	vector<ll> arr(n);
	for(auto &it:arr){
		cin>>it;
		s+=it;  
	}
	for(auto i=n-1;i>=0;--i){
		s-=arr[i];
		ans+=(s%p*arr[i])%p;
		ans%=p;
	}
	cout<<ans<<'\n';
	return 0;
}
//prime func
//subset production
//factorization
//modpow
//modinv ( a^(p-2)=a^(-1) (mod p) )
//sieve
//ncr
//euler totien func (co prime divisiors upto n)
//matrix exponentation
//dsu
//Trees
//Graphs(dfs,bfs,shortes path etc.)
//DP-Recursion