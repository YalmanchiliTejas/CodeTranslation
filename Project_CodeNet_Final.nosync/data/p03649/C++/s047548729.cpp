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
	vector<ll> Ais(N);
	rep(i,0,N) {
		cin >>	Ais[i];
	}
	ll ans = 0;
	rep(i,0,N) {
		ans += Ais[i] / (N+1);
		Ais[i] = Ais[i] % (N+1);
	}
	rep(i,0,N) {
		Ais[i] += ans;
	}
	sort(Ais.rbegin(), Ais.rend());
	ll add = numeric_limits<ll>::max();
	rep(i,0,N) {
		add = min(add, max((ll)0, (Ais[i]-(N-1)) * N) + i);
		// cout << "i: " << i << " Ais[i]: " 
		//	<< Ais[i] << " N: " << N << "add: " << add << endl;
		Ais[i] -= N;
		rep(j,0,N) {
			if (i != j) {
				Ais[j] += 1;
			}
		}
	}
	ans += add;
	cout << ans << endl;
}

