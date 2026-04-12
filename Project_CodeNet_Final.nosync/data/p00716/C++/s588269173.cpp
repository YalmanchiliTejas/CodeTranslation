#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
	int n;
	cin >> n;
	while(n--) {
		ll money;
		cin >> money;
		int y, k;
		cin >> y >> k;
		ll maxi = 0;
		rep(i, k) {
			ll m = money;
			int z, mpy;
			double r;
			cin >> z >> r >> mpy;
			ll res = 0;
			if(z==0) {
				ll add = 0;
				rep(j, y) {
					add += r * m;
					m -= mpy;
				}
				res = add + m;
			} else {
				res = m;
				rep(j, y) {
					res += r * res - mpy;
				}
			}
			maxi = max(maxi, res);
		}
		cout << (ll)maxi << endl;
	}
	return 0;
}