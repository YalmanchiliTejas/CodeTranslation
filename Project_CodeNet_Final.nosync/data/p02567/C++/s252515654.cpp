#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<atcoder/all>

using ll=long long;

ll op(ll a, ll b) {
	return std::max(a, b);
}

ll e() {
	return -1;
}

ll target;

bool f(ll v) { return v < target; }

using namespace std;
int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	atcoder::segtree<ll, op, e> st(A);

	for (int i = 0; i < Q; i++) {
		ll T;
		cin >> T;
		if (T == 2) {
			ll L, R;
			cin >> L >> R;
			L--;
			cout << st.prod(L, R) << endl;
		}
		else {
			ll X, V;
			cin >> X >> V;
			X--;
			if (T == 1) {
				st.set(X, V);
			}
			else {
				target = V;
				cout << st.max_right <f>(X)+1 << endl;
			}
		}
	}

	return 0;
}

