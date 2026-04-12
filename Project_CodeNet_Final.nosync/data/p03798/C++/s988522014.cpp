#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
int main () {
	int n;
	string ans;
    cin >> n >> ans;
	ans += ans;
	const char *v[4] = {"SS", "SW", "WS", "WW"};
	vector<char> zoo(2*n);
	rep(k,4) {
		zoo[0] = v[k][0];
		zoo[1] = v[k][1];
		for (int i = 1; i <= n; ++i) {
			if ((zoo[i] == 'S' && ans[i] == 'o') || (zoo[i] == 'W' && ans[i] == 'x')) {
				zoo[i+1] = zoo[i-1];
			} else {
				if (zoo[i-1] == 'S')
					zoo[i+1] = 'W';
				else
					zoo[i+1] = 'S';
			}
		}
		if (zoo[0] == zoo[n] && zoo[1] == zoo[n+1]) {
			string ans = "";
			rep(i,n) ans += zoo[i];
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}