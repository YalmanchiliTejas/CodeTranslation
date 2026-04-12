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
	int n;
	cin >> n;
	vector <int> A(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		v[i] = A[i];
	}
	sort(all(v));
	for (int i = 0; i < n; i++) {
		int id = lower_bound(all(v), A[i]) - v.begin();
		id += 1;
		if(id <= n / 2) {
			cout << v[n / 2] << "\n";
		} 
		else {
			cout << v[n / 2 - 1] << "\n";
		}
	}
}
