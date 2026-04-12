#include <bits/stdc++.h> 
#define ll long long
#define ld long double
#define vi vector<int>
#define vl vector<ll> 
#define vd vector<double>
#define vld vector<long double>
#define vp vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define pb push_back
#define pi pair<int, int>
#define pl pair<ll, ll>
#define mp make_pair
#define fi first
#define sc second
#define for0(i, n) for(ll i=0; i<n; i++) 
#define for1(i, n) for(ll i=1; i<=n; i++)
using namespace std;
const ll mod = 1e9+7;

void solve(){
	ll x; cin>>x;
	if(x>=30)
		cout<<"Yes";
	else
		cout<<"No";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll test = 1;
	//cin>>test;
	while(test--)
		solve();

	return 0;
}