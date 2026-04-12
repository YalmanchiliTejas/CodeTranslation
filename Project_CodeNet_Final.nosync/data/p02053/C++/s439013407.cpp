#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int H, W, res;
char c;
vector<int>v[1000];

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> c;
			if (c == 'B') {
				v[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		if (!v[i].empty()) {
			for (int j = 0; j < H; ++j) {
				if (!v[j].empty()) {
					res = max(res, abs(i - j) + max(abs(v[i].front() - v[j].back()), abs(v[i].back() - v[j].front())));
				}
			}
		}
	}
	cout << res << endl;
}
