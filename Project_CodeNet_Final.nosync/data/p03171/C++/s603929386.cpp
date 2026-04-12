// deque
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
const int inf = (1<<30);
string toBin(ll a){
	int i;
	string s1="";
	while(a>0){
		if(a&1){
			s1="1"+s1;
		}else{
			s1="0"+s1;
		}
		a>>=1;
	}
	return s1;
}
ll dp[5000][5000];

ll fun(ll arr[], ll s, ll e, bool t){
	if(s>e){
		return 0;
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	ll c=0;
	if(t){
		ll a=arr[s]+fun(arr, s+1, e, !t);
		ll b=arr[e]+fun(arr, s, e-1, !t);
		c=max(a, b);
	}else{
		ll a=fun(arr, s+1, e, !t);
		ll b=fun(arr, s, e-1, !t);
		c=min(a, b);
	}
	return dp[s][e]=c;
}

void solve(){
	ll i, n, sum=0;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	memset(dp, -1, sizeof(dp));
	ll x=fun(arr, 0, n-1, true);
	sum=accumulate(arr, arr + n, 0LL);
	cout<<(2*x- sum)<<endl;
}

int main()
{
	solve();
	return 0;
}