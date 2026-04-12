#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

vector<ll> sum[101010],rsum[101010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<ll>s(N),rs(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		rs[N - 1 - i] = s[i];
	}
	for (int k = 1; k < N;k++) {
		sum[k].pb(0);
		rsum[k].pb(0);
		for (int i = k; i < N; i+=k) {
			sum[k].pb(sum[k].back() + s[i]);
			rsum[k].pb(rsum[k].back() + rs[i]);
		}
	}

	ll ans = 0;
	for (int k = 1; k < N; k++) {
		for (int x = 1; (x-1)*k < N; x++) {
			ll A = N - 1 - (x - 1)*k;
			ll B = A - k;
			if (A > 0 && B > 0) {
				if (A%k != 0 || A > (x - 1)*k) {
					ans = max(ans, sum[k][x - 1] + rsum[k][x - 1]);
				}
			}
		}
	}
	puts(ans);

	return 0;
}