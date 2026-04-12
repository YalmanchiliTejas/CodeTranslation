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
#include "numeric"
#include "cassert"
#include "functional"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<vector<int>>v(H, vector<int>(W));
	for (auto &i : v)for (auto &j : i)cin >> j;
	vector<int>from;
	vector<int>to;
	vector<string>cost;
	for (int i = 0; i < 200; i++) {
		from.push_back(i + 1);
		to.push_back(i + 2);
		if (i < 100)cost.push_back("X");
		else cost.push_back("Y");
	}
	for (int i = 0; i < H*W; i++) {
		int h = i / W;
		int w = i % W;
		h++;
		w++;
		int nj = -1;
		int nk = -1;
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; j + k <= 100&&k<100; k++) {
				int add = v[h - 1][w - 1] - j * h - k * w;
				if (add < 0)continue;
				if (!i&&add)continue;
				bool flag = true;
				for (int l = 0; l < H*W; l++) {
					if (i == l)continue;
					int nh = l / W;
					int nw = l % W;
					nh++;
					nw++;
					if (j*nh + k * nw + add < v[nh - 1][nw - 1]) {
						flag = false;
					}
				}
				if (flag) {
					nj = j;
					nk = k;
				}
			}
		}
		if (nj == -1) {
			cout << "Impossible\n";
			return 0;
		}
		//cout << i << endl;
		if (!i) {
			from.push_back(nj + 1);
			to.push_back(201 - nk);
			cost.push_back(to_string(0));
		}
		else {
			//	cout << i << endl;
			from.push_back(nj + 1);
			to.push_back(201 + i);
			cost.push_back(to_string(0));
			from.push_back(201 + i);
			to.push_back(201 - nk);
			cost.push_back(to_string(v[h - 1][w - 1] - nj * h - nk * w));
		}
	}
	cout << "Possible\n";
	cout << 200 + H * W << " " << from.size() << endl;
	for (int i = 0; i < from.size(); i++) {
		cout << from[i] << " " << to[i] << " " << cost[i] << endl;
	}
	cout << 1 << " " << 201 << endl;
}