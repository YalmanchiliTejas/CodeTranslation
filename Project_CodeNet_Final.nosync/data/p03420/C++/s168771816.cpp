#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=100010, inf=2e9;
int n, k;
ll ans=0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int b=k+1; b<=n; b++){
		ll x=n/b, r=n%b;
		ans+=x*(b-k) + max(0LL, r-k+1) - (k==0);
	}
	cout<<ans;
	return 0;
}