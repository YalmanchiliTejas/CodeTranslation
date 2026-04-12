#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
typedef long long ll;
typedef long double ld;
typedef unsigned int  ull;
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define int ll
#define pll pair<ll, ll> 
#define pdd pair<ld, ld> 
#define pb push_back
#define reset(x,v) memset(x,v,sizeof(x))
#define mod 998244353
using namespace std;

ll power(ll x, ll y){  
	if(x == 1 || y == 0)
		return 1;
    ll res = 1;   
    x = x % mod; 
    if (x == 0) 
		return 0;  
    while (y > 0){  
        if (y & 1)  
	        res = (res * x) % mod;  
        y = y >> 1; 
        x = (x * x) % mod;  
    }  
    return res;  
} 

signed main(){
	FASTIO
	int n, x, m;
	cin >> n >> x >> m;
	unordered_map<int, int> mp, sum;
	int a = 0, b = 0, c = 0;
	int i = 0;
	while(mp.count(x) == 0){
		mp[x] = i;
		b += x;
		sum[i] = b;
		i++;
		x = (x * x) % m;
	}
	a = sum[mp[x]-1];
	b -= a;
	int numCycle = (n - mp[x]) / (i - mp[x]);
	b *= numCycle;
	int rem = (n - mp[x]) % (i - mp[x]);
	c = sum[mp[x] + rem - 1] - sum[mp[x] - 1];
	cout << a + b + c;
    return 0;
}
