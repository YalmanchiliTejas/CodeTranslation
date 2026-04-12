#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
using namespace std;
using ll =long long;
const int MOD = 1000000007;

//////検証する数,超えられない数////
long long cine(long long a, long long b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
};
//vector型の初期化
void vec_initialize(vector<ll>& a, const ll N) {
	ll c;

	for (int i = 0; i < N; i++) {

		cin >> c;
		a.push_back(c);

	}

};

void vec2_initialize(vector<ll>& a, vector <ll>&b, const ll N) {
	ll c,d;

	for (int i = 0; i < N; i++) {

		cin >> c>>d;
		a.push_back(c);
		b.push_back(d);
	}

};

void vec_pair_initialize(vector<pair<ll, ll>>& a, const ll N) {
	ll c, d;
	for (int i = 0; i < N; i++) {
		cin >> c >> d;
		a.push_back(make_pair(c, d));
	}
};

int main() {
	ll H, W;
	cin >> H >> W;
	vector<string>a;
	string s;

	for (int i = 0; i < H; i++) {
		cin >> s;
		a.push_back(s);
	}

	for (int i = 0; i < H;i++) {
		for (int j = 0; j < W; j++) {

			if (a[i][j] == '#') {

				break;

			}
			if (j == W - 1) {
				for (int k = 0; k < W; k++) {

					a[i][k] = 'x';

				}

			}
		}


	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {

			if (a[j][i] == '#') {

				break;

			}
			if (j == H - 1) {
				for (int k = 0; k < H; k++) {

					a[k][i] = 'x';

				}

			}
		}
	}
	ll cnt=0;
	for (int i = 0; i < H; i++) {
		cnt = 0;
		for (int j = 0; j < W; j++) {

			if (a[i][j]!='x') {

				cout << a[i][j];

				

			}
			else {

				cnt++;

			}
		}
		if (cnt != W) {
			cout << endl;
		}
	}

}