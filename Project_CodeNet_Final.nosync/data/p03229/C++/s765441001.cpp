#include <bits/stdc++.h>

using namespace std;

static const int INF = 1e9 + 7;

template<typename T>
using Vec = vector<T>;

template<typename T, typename T2>
using P = pair<T, T2>;

template<typename... Args>
using Tup = tuple<Args...>;

template<typename T>
using qp = priority_queue<T, Vec<T>, greater<T> >;

template<typename T>
using pq = priority_queue<T>;

using llong = long long;
using ullong = unsigned long long;
using uint = unsigned int;

template<typename T>
T gcd(T x, T y)
{
	return y ? gcd(y, x % y) : x;
}

void hawawa()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto&& i : a) {
		cin >> i;
	}
	sort(begin(a), end(a));
	if (n % 2) {
		long long ans1 = 0, ans2 = 0;
		swap(a[0], a[n / 2 - 1]);
		for (int i = 0; i < n / 2; i++) {
			ans1 += abs(a[i] - a[n / 2 + 1 + i]) + abs(a[i + 1] - a[n / 2 + 1 + i]);
		}
		swap(a[0], a[n / 2 - 1]);

		if (n / 2 + 1 < n) {
			swap(a[n / 2 + 1], a[n - 1]);
		}

		for (int i = 0; i < n / 2; i++) {
			ans2 += abs(a[i] - a[n / 2 + i]) + abs(a[i] - a[n / 2 + 1 + i]);
		}
		cout << max(ans1, ans2) << "\n";
	}
	else {
		swap(a[0], a[n / 2 - 1]);
		swap(a[n / 2], a[n - 1]);
		long long ans = abs(a[0] - a[n / 2]);
		for (int i = 1; i < n / 2; i++) {
			ans += abs(a[n / 2 + i - 1] - a[i]) + abs(a[n / 2 + i] - a[i]);
		}
		cout << ans << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
}
