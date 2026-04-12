#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
#define rep(i,a)  for(ll i=0; i< a; i++)
#define pb push_back
#define vl vector<ll>
#define trace(x)  cerr << #x << ": " << x << endl;
void __print(ll x) {cerr << x;}
void __print(ld x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const ll N=1e9+7;

int main()
{
	fast;
	ll n;cin>>n;
	vector<ll> v(n);vector<ll> pref(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		pref[i]=v[i];
		if(i)pref[i]+=pref[i-1];
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ll z=pref[n-1]-pref[i];z%=N;
		z*=v[i];
		z%=N;ans+=z;ans%=N;
	}
	cout<<ans;


}