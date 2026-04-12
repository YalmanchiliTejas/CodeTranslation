//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
	ll N;
	cin >> N;
	vector<ll> As(N);
	rep(i,0,N) {
		ll A;
		cin >> As[i];
	}
	sort(As.begin(), As.end());
	ll ans = 0;
	if (N % 2 == 0) {
		rep(i,0,N-1) {
			ll coef = 2 * min(i+1, N-1-i);
			if (i == N/2-1) {
				coef--;
			}
			ans += (As[i+1]-As[i]) * coef;
		}
	} else {
		rep(i,0,N-1) {
			ll coef = 2 * min(i+1, N-1-i);
			if (i == N/2-1 || i == N/2) {
				coef--;
			}
			ans += (As[i+1]-As[i]) * coef;
		}
		ans += max(As[N/2]-As[N/2-1], As[N/2+1]-As[N/2]);
	}
	cout << ans << endl;
}
