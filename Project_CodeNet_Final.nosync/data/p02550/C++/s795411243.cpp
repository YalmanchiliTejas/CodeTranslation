#include "bits/stdc++.h"
using namespace std;
#include "string"
#define int long long
#define pi pair <int, int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#define endl '\n'

class SequenceSum {
private:
	int n, x, m;
	map < int, int > mp, id;

public:
	SequenceSum(int _n, int _x, int _m) {
		n = _n;
		x = _x;
		m = _m;
	}

	int solve() {
		int cur = x, cnt = 1, ans = 0;
		mp[0] = 0;
		while(cnt <= n) {
			if(cur <= 1) {
				ans += (n - cnt + 1)*cur;
				break;
			} 
			if(mp.find(cur) != mp.end()) {
				int tmp = ans;
				n -= (cnt - 1);
				ans += (n / (cnt - mp[cur]))*(tmp - id[mp[cur] - 1]);
				n %= (cnt - mp[cur]);
				ans += id[mp[cur] + n - 1] - id[mp[cur] - 1];
				break;
			}
			ans += cur;
			mp[cur] = cnt;
			id[cnt] = ans;
			cnt++;
			cur = (cur * cur ) % m;
		}
		return ans;
	}
};

int32_t main() {
	boost;
	int n, x, m;
	cin >>  n >> x >> m;
	SequenceSum ss(n, x, m);
	cout << ss.solve() << endl;
}