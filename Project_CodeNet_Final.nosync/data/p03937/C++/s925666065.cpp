#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007LL;
typedef pair<int, int> P;
char a[8][9];
int main() {
	int H, W;
	cin >> H >> W;
	vector<P> v;
	for (int i = 0; i < H; i++) {
		cin >> a[i];
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#') v.emplace_back(j, i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[i].first<v[j].first && v[i].second > v[j].second) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
}