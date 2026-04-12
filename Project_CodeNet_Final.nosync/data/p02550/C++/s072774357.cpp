#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using lint = long long;

lint n, x, m, w, cnt1, cnt2, sum1, res;
vector<lint>vec;
bool used[100010];
int main() {
	cin >> n >> x >> m;

	lint a1 = x;
	while (true) {
		used[a1] = true;
		vec.push_back(a1);
		a1 = a1 * a1 % m;
		if (used[a1]) {
			w = a1;
			break;
		}
	}

	cnt1 = find_if(vec.begin(), vec.end(), [=](lint x) { return w == x; }) - vec.begin();
	cnt2 = vec.size() - cnt1;

	if (n < cnt1) {
		cout << accumulate(vec.begin(), vec.begin() + n, 0LL) << endl;
	}
	else {
		res = accumulate(vec.begin(), vec.begin() + cnt1, 0LL);

		n -= cnt1;
		sum1 = accumulate(vec.begin() + cnt1, vec.end(), 0LL);
		res += n / cnt2 * sum1;

		n %= cnt2;
		res += accumulate(vec.begin() + cnt1, vec.begin() + cnt1 + n, 0LL);
		cout << res << endl;
	}
}