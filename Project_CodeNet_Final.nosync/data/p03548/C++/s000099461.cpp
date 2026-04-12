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
	long long x, y, z;
	cin >> x >> y >> z;
	for (int i = 100000; i >= 0; i--) {
		if (x >= y * i + z * i + z) {
			cout << i << "\n";
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
}
