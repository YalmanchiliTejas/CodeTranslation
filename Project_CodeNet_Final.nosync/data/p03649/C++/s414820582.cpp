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
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

/*
 * The largest number should become less than n
 * 
 * If k <= 10^16 + 1000 we can directly take a single element of k - 1
 * Take everything as multiples of n
 * n * x1 +  
 * whenever there are a few numbers you can keep on subtracting n from a number until it's
 * value is less than n
 * that should be ai/n ops and ai/n should be added to others and ai = ai % n
 * until all the values are less than n
 * 
 * 4 4 and n = 2
 * (2 5) -> (3 3) -> (1 4) -> (2 2) -> (0 3) -> (1 1)
 * 5 5 and n = 2
 * (3 6) -> (4 4)
 * 4 4 4 and n = 3
 * (2 5 5) -> (3 3 6) -> (4 4 3)
 *
 * (49/50)*(49/50) * MX 
 * */

int main() {
	int n;
	cin >> n;
	vector <ll> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	ll ans = 0;
	while(true) {
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if (A[i] < n) continue;
			pos = 1; 
			for (int j = 0; j < n; j++) {
				if (i != j) {
					A[j] += (A[i] / n);
				}
			}
			ans += (A[i] / n);
			A[i] = A[i] % n;
		}
		if (pos == -1) {
			break;
		}
	}
	cout << ans;
}
