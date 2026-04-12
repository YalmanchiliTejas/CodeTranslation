#include<bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define inf 1e9
#define pi 3.1415926536
#define mod 1000000007
#define fr(i,a,b,in) for(int i=a;i<b;i+=in)
#define frn(i,a,b,dc) for(int i=a;i>=b;i-=dc)
#define test(t) int t; cin>>t; while(t--)
int main()
{
	fastio();
	int n;
	cin>>n;
	ll a[n],tot=0;
	fr(i,0,n,1) cin>>a[i];
	fr(i,0,n,1) tot+=a[i];
	ll ans=0;
	fr(i,0,n,1){
		tot-=a[i];
		ans=(ans + (a[i]*(tot%mod))%mod)%mod;
	}
	cout<<ans<<endl;
}