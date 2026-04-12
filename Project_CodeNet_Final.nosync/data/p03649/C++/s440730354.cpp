#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_N = 55;

ll compute_mx(const vector<ll> &inp);
ll ceil_div(ll a, ll b);

int main()
{
	int N;
	cin >> N;
	vector<ll> inp(N);

	for (int i = 0; i < N; ++i) {
		cin >> inp[i];
	}

	ll K = 0;
	while(compute_mx(inp) > N - 1) {
		ll temp = 0;
		for (auto &x : inp) {
			if (x >= N) {
				temp += ceil_div(x - N + 1, N);
			}
		}

		K += temp;
		for (auto &x : inp) {
			if (x >= N) {
				ll b = ceil_div(x - N + 1, N);
				x -= b * N;
				x += (temp - b);
			} else {
				x += temp;
			}
		}
	}

	cout << K << endl;
}

ll compute_mx(const vector<ll> &inp)
{
	ll mx = 0;
	for (auto &x : inp) {
		mx = max(mx, x);
	}

	return mx;
}

ll ceil_div(ll a, ll b)
{
	return (a / b) + (a % b > 0);
}