

#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX-1;
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };

ll sum(ll mi, ll ma) {
	ll res = (ma + 1)*ma / 2 - mi * (mi - 1) / 2;
	return res;
}



int main(){
	ll n, k;
	cin >> n >> k;

	ll ans = 0;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}
	for (int b = k + 1; b <= n; b++) {
		ll s = (n + 1) / b;
		ans += s * (b - k);

		ll l = k + s * b;
		if (n >= l)ans += n - l + 1;
	}
	cout << ans << endl;
	return 0;
}