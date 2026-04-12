#include <iostream>
#include <algorithm> 
#include <cmath>
//#include <bitset>
//#include <deque>
#include <iterator>
#include <map> 
//#include <queue>
//#include <stack>
#include <string>
#include <vector>
#include <array>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 



int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	string ans = "";
	string z = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; ++i) {
		int minn = 1e9 + 7;
		for (int j = 0; j < n; ++j) {
			int p = 0;
			for (int k = 0; k < (int)s[j].size(); ++k) {
				if (s[j][k] == z[i]) {
					p++;
				}
			}
			minn = min(minn,p);
		}
		for (int j = 0; j < minn; ++j) {
			ans += z[i];
		}
	}
	cout << ans;
} 









