// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int A[N], B[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	deque<int> dq;
	for (int i = 0; i < n / 2; i++) {
		if (i & 1) dq.push_back(A[i]), dq.push_front(A[n - i - 1]);
		else dq.push_back(A[n - i - 1]), dq.push_front(A[i]);
	}
	if (n & 1) {
		if (abs(A[n / 2] - dq.back()) > abs(A[n / 2] - dq.front())) dq.push_back(A[n / 2]);
		else dq.push_front(A[n / 2]);
	}
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) sum += abs(dq[i + 1] - dq[i]);
	cout << sum << endl;

	return 0;
}
