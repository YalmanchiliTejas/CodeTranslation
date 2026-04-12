#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define F first
#define S second
#define pb push_back
#define f(i,s,n) for(int i=(int)s;i<=(int)n;++i)
#define Fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define mod 1000000007
using namespace std;
void solve()
{	
	int n;cin>>n;
	vll a(n);
	f(i,0,n-1)cin>>a[i];
	ll sum=0;
	vll suf(n+1);
	suf[n-1]=a[n-1];
	for(int i=n-2;i>=0;--i){
		suf[i]=(suf[i+1]%mod+a[i]%mod)%mod;
	}
	f(i,0,n-2){
		sum=(sum%mod + (a[i]%mod*(suf[i+1]%mod))%mod)%mod;
	}
	cout<<sum<<'\n';

}
int main()
{	Fast;
//	int t;cin>>t;
//	while(t--)
	solve();
}