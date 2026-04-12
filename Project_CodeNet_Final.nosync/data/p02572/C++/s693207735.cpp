#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;

int main() {
	ll N; cin >> N;
	vector<ll> A(N);
	ll sum = 0;
	ll mod = 1e9 + 7;
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		sum += A.at(i);
	}
	ll buf = sum, ans = 0;
	for (int i = 0; i < N; i++) {
		sum -= A.at(i);
		buf = sum;
		sum %= mod;
		ans += sum * A.at(i);
		ans %= mod;
		sum = buf;
	}
	cout << ans << endl;
}
