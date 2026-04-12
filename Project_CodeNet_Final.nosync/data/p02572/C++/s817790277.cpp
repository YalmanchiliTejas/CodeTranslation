#include<iostream>
#include<array>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;
#define ll long long
#define ff first
#define ss second
#define e endl

void solve() {
	ll n; cin >> n;
	vector<ll> a;
	ll sum[200001], m = 1e9+7, y = 0;
	for(ll i = 0;i < n;i++){
		ll x; cin >> x;
		a.push_back(x);
		
	}
	memset(sum, 0, sizeof(sum));
	for(ll i = n-1;i >= 0;i--){
		if(i != n-1){
			sum[i] = (sum[i+1] + a[i+1])%m;
		}
	}
	ll x = 0;
	for(ll i = 0;i < n;i++){
		x = (x + (sum[i]*a[i])%m)%m;
	}
	
	cout << x << endl;
}

int main()
{
	//ll t; cin >> t; while (t--)
	solve();
	
}