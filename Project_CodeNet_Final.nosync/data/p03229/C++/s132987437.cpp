#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;
#define ll long long
#define cpp mp::cpp_int
#define dequeue deque
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = 1; i <= n; i++)
#define drep(i, n) for(int i = n-1; i >= 0; i--)
#define srep(i, s, t) for (int i = s; i < t; i++)
#define vi vector<int>
#define P pair<ll, ll>
int mod = 1'000'000'000 + 7;
struct edge {
	int to;
	ll cost;
};

void COME_LET_THE_GAMES_BEGIN() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(20);
}
void reverse(string* s) {
	reverse((*s).begin(), (*s).end());
}
ll N;
ll A[100000];
ll B[300000];
ll C[300000];
ll x() {
	int k = (N - 1) * 2 + 1;
	C[0] = 0;
	for (int i = 1; i <= k; i++) {
		C[i] = abs(B[i] - B[i - 1]);
		C[i] += C[i - 1];
	}
	ll res = 0;
	for (int i = N - 1; i <= k; i++) {
		res = max(res, C[i] - C[i - (N - 1)]);
	}
	return res;
}
void y() {
	for (int i = 0; i * 2 < N; i++) {
		B[i * 2] = A[i];
	}
	reverse(A, A + N);
	for (int i = 0; i * 2 + 1 < N; i++) {
		B[i * 2 + 1] = A[i];
	}
	reverse(A, A + N);
	for (int i = N; i < N + N; i++) {
		B[i] = B[i - N];
	}
}
int main() {
	COME_LET_THE_GAMES_BEGIN();
	cin >> N;
	rep(i, N)cin >> A[i];
	sort(A, A + N);
	y();
	ll ans = x();
	reverse(A, A + N);
	y();
	ans = max(ans, x());
	cout << ans << endl;
}