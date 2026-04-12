#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>
#include<queue>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int H, W;
	cin >> H >> W;

	vector<vector<bool>> a(H, vector<bool>(W));
	char temp;
	for (Int i = 0; i < H; i++) {
		for (Int j = 0; j < W; j++) {
			cin >> temp;
			if (temp=='#') {
				a[i][j] = true;//黒
			}
			else {
				a[i][j] = false;//白
			}
		}
	}

	//横方向に見る
	bool flag;
	vector<vector<bool>> b;
	for (Int i = 0; i < H; i++) {
		flag = false;//falseなら全部白
		for (Int j = 0; j < W; j++) {
			if (a[i][j]) {
				flag = true;
			}
		}
		if (flag) {//一つでも黒がある場合
			b.push_back(a[i]);
		}
	}

	Int len = b.size();
	//縦方向に見る
	vector<vector<bool>> c(len);
	for (Int j = 0; j < W; j++) {
		flag = false;
		for (Int i = 0; i < len; i++) {
			if (b[i][j]) {
				flag = true;
			}
		}
		if (flag) {
			for (Int i = 0; i < len; i++) {
				c[i].push_back(b[i][j]);
			}
		}
	}

	Int len2 = c[0].size();
	for (Int i = 0; i < len; i++) {
		for (Int j = 0; j < len2; j++) {
			if (c[i][j]) {
				cout << '#';
			}
			else {
				cout << '.';
			}
		}
		cout << "\n";
	}

}
