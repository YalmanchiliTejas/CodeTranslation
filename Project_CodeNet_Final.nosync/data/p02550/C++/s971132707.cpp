#include <iostream>
#include <map>
#include <tuple>

using namespace std;

int main()
{
	long long n, x, m;
	cin >> n >> x >> m;
	long long ans = 0;
	map<long long, tuple<long long, long long, int>> mp; //xが出てきた数, sum, i
	bool f = true;
	for (long long i = 1; i <= n; i++) {
		ans += x;
		if (f) {
			if (get<0>(mp[x]) == 1) {
				f = false;
				
				long long t = ans - get<1>(mp[x]);
				ans += (n - i) / (i - get<2>(mp[x])) * t;
				n -= (n - i) / (i - get<2>(mp[x])) * (i - get<2>(mp[x]));
			}
			else {
				get<0>(mp[x])++;
				get<1>(mp[x]) = ans;
				get<2>(mp[x]) = i;
			}
		}
		x = x * x % m;
	}
	cout << ans << endl;

	return 0;
}