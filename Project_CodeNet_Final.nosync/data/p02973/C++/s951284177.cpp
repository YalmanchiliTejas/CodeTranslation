#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <set>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
const ll inf = (1LL << 60);
const ll mod = 1000000007;
ll max(ll a, ll b) {
	if (a < b)
		return b;
	else
		return a;

}
ll min(ll a, ll b) {
	if (a < b)
		return a;
	else
		return b;

}


int main() {
	ll N;
	
	cin >> N;
	vector<ll> A(N);
	
	rep(i, N) {
		cin >> A[i];
		
	}

	ll cnt = 0;
	multiset<ll> M;
	
	for (int i = 0; i < N; i++) {
		decltype(M)::iterator it;
		it = M.lower_bound(A[i]);

		if (it == M.begin()) {
			M.insert(A[i]);
			continue;
		}
		M.erase(--it);
		M.insert(A[i]);
	}

	cout << M.size() << endl;

	return 0;
}