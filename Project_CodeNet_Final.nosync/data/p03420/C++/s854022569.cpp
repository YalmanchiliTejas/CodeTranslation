#prag\
ma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int x=i-k;
		if(x<0) continue;
		ans+=(ll)(n/i)*(ll)x;
		if(n%i!=0&&n%i>=k) ans+=(ll)((n%i)-max(k,1)+1);
	}
	cout<<ans;
}