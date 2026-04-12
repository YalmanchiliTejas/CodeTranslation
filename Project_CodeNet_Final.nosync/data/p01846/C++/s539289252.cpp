#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	while (s != "#") {
		int sy, sx, gy, gx;
		cin >> sy >> sx >> gy >> gx;
		sy--;
		sx--;
		gy--;
		gx--;
		vector<string>field;
		s += '/';
		string t;
		for (auto i : s) {
			if (i == '/') {
				field.push_back(t);
				t.clear();
				continue;
			}
			if (i == 'b') {
				t.push_back('b');
				continue;
			}
			for (int j = '0'; j < i; j++) {
				t.push_back('.');
			}
		}
		swap(field[sy][sx], field[gy][gx]);
		H = field.size();
		W = field[0].size();
		string ret;
		for (int i = 0; i < H; i++) {
			int num = 0;
			for (int j = 0; j < W; j++) {
				if (field[i][j] == 'b') {
					if (num) {
						ret+=to_string(num);
					}
					ret += 'b';
					num = 0;
				}
				else {
					num++;
				}
			}
			if (num) {
				ret += to_string(num);
			}
			ret += '/';
		}
		ret.pop_back();
		cout << ret << endl;
		cin >> s;
	}
	return 0;
}
