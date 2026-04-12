//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502
#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
struct Cube {
	int f[6];
	int sum;
	Cube() {
		f[0] = 1; f[1] = 2; f[2] = 3; f[3] = 4; f[4] = 5; f[5] = 6;
		sum = 1;
	}
	void roll(int i, int j, int k, int l) {
		int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
	}
	void n() { roll(0, 1, 5, 4); sum += f[0]; }
	void e() { roll(0, 3, 5, 2); sum += f[0]; }
	void w() { roll(0, 2, 5, 3); sum += f[0]; }
	void s() { roll(0, 4, 5, 1); sum += f[0]; }
	void r() { roll(1, 2, 4, 3); sum += f[0]; }
	void l() { roll(2, 1, 3, 4); sum += f[0]; }
};
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		int n; cin >> n;
		if (!n) break;
		Cube c;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (s == "North")c.n();
			else if (s == "East")c.e();
			else if (s == "South")c.s();
			else if (s == "West")c.w();
			else if (s == "Right")c.r();
			else if (s == "Left")c.l();
		}
		cout << c.sum << endl;
	}
	return 0;
}