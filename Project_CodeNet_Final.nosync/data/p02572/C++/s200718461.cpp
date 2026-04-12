#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include "math.h"
#include "assert.h"

using namespace std;

#define ll long long

#define buff ios::sync_with_stdio(false)
#define epsilon 1e-07
#define pi 2 * acos(0.0);
#define mod 1000000007   // 1e9+7
#define cerr if(false)cerr
#define watch(x) cerr << #x << " = " << x << endl;

#define xy pair<int, int>
#define x first
#define y second 

#define inf std::numeric_limits<int>().max()

int main() {
	int n;
	cin >> n;
	vector<ll> v(n); 
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	vector<ll> s(n);
	s[0] = v[0];
	for(int i=1; i<n; i++) {
		s[i] = (s[i-1]%mod + v[i]%mod) % mod; 
	}
	ll ans = 0;
	for(int i=1; i<n; i++) {
		ans += (v[i]%mod * s[i-1]%mod) % mod;	
		ans %= mod;
	}
	cout << ans << endl;
}

