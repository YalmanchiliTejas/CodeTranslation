#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

constexpr int INF = 2000000000;
constexpr ll LLINF = 9000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	vi B(N+N, 0LL);
	int l = N, r = N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (l <= r)
			B[r++] = a;
		else
			B[--r] = a;
		swap(l, r);
	}
	
	if (l > r) {
		swap(l, r);
		reverse(B.begin()+l, B.begin()+r);
	}
	for (int i = l; i < r; ++i)
		cout << B[i] << " \n"[i+1==r];
	
	return 0;
}
