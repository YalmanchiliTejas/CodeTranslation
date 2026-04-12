#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define in auto&it
#define out auto it
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
const double pi = acos(-1);
#define err(x) cerr<<#x<<" = "<<x<<'\n';
int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	fastio
	int n;
	cin>>n;
	ll ar[n];
	for(int i=0;i<n;++i) cin>>ar[i];
	vector<int>suf(n);
	suf[n-1]=0;
	suf[n-2]=ar[n-1]%mod;
	for(int i=n-3;i>=0;--i){
		suf[i]=((ar[i+1])%mod+(suf[i+1])%mod)%mod;
	//for(auto x:suf) cerr<<x<<" ";
		suf[i]%=mod;
	}
	ll ans=0;
	for(int i=0;i<n-1;++i){
		ans+=((ar[i]%mod)*(suf[i]%mod))%mod;
		ans%=mod;
	}
	cout<<(((ans%mod)+mod)%mod);
	return 0;
}