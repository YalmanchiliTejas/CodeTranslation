#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 998244353
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	int n, k;
	cin >> n >> k;
	vector <ll> A(n + 1);
	for (int i = 1; i <= n; i++) {
		A[0] += (n / i);
		A[i] -= (n / i);
		if(n % i != 0) {
			A[1] += 1;
			A[n % i + 1] -= 1;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		if(i > 0)
			A[i] += A[i - 1];
		if(i >= k) {
			ans += A[i];
		}
	}
	cout << ans;
}
