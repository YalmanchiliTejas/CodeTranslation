#include <vector>
#include <iostream>
#include <deque>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

#define ff first
#define ss second

int main() {

	int n; cin >> n;
	deque<long long> dq;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		dq.push_front(a);

		while (dq.size() > 2) {
			long long curr = dq.front(); dq.pop_front();
			long long prev = dq.front(); dq.pop_front();
			long long spre = dq.front(); dq.pop_front();

			if (prev >= curr and prev >= spre) dq.push_front(curr + spre - prev);
			else {
				dq.push_front(spre);
				dq.push_front(prev);
				dq.push_front(curr);
				break;
			}
		}
	}

	long long ans = 0;
	int sgn = 1;
	while (!dq.empty()) {
		if (dq.front() > dq.back()) {
			ans += (sgn * dq.front());
			dq.pop_front();
		}
		else {
			ans += (sgn * dq.back());
			dq.pop_back();
		}
		sgn = -sgn;
	}

	cout << ans;
	return 0;
}