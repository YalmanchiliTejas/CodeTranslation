/*#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
*/

/*
ID: febrian3 
LANG: C++11 
PROB: task 
*/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
const ll nax = 0;
ll n;

int main(){
		/*freopen("filename.in","r",stdin); 
		freopen("filename.out","w",stdout);*/ 
		IOS	
		cin >> n;
		vector<ll>arr(n+1);
		for(int i=0;i<n;++i){
			cin >> arr[i];
		}
		vector<ll>pref(n, 0);
		for(int i=n-1;i>=0;--i){
			pref[i]=arr[i]%mod;
			if(i<n-1) pref[i]=(pref[i]%mod+pref[i+1]%mod)%mod;
		}
		ll ans=0;
		for(int i=0;i<n-1;++i){
			ll cur=((arr[i]%mod)*(pref[i+1]%mod))%mod;
			ans=(ans+cur)%mod;
		}
		cout << ans << '\n';
	}
