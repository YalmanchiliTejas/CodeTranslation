#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq; //min heap

#define dodebug(i, n, arr)	for(int i=0;i<n;++i)	cout<<arr[i]<<" ("<<i<<")\n";

ll gcd(ll a,ll b){	if(b == 0)	return a;return gcd(b,a%b);}
ll binpow(ll n,ll x){	ll ans = 1;while(x){if(x & 1)	ans *= n;n *= n;x >>= 1;}return ans;}

int n;
vector<ll> a(3010);
vector<vector<ll> > dp(3010, vector<ll>(3010, -1));

ll dodp(int l, int r){
	// cout<<"doing for "<<l<<" "<<r<<'\n';
	if(l==r)	return a[l];
	// if(l>r)		return 1e10;
	if(dp[l][r] != -1)	return dp[l][r];

	dp[l][r] = max(a[l] - dodp(l+1,r), a[r] - dodp(l,r-1));

	return dp[l][r];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0;i<n;++i)	cin>>a[i];

	// cout<<dodp(0, n-1)<<'\n';
	//note the recursive call happens successively, and it returns for the first time when it reaches single element and the end
	//therefore an iterative approach is:
	for(int l=n-1;l>-1;--l){
		for(int r=l;r<n;++r){
			if(l==r)	dp[l][r] = a[l];
			else		dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
		}
	}

	cout<<dp[0][n-1]<<"\n";

	// for(int l=0;l<n;++l){
	// 	for(int r=0;r<n;++r)	cout<<dp[l][r]<<" ";
	// 	cout<<"\n";
	// }

	return 0;
}