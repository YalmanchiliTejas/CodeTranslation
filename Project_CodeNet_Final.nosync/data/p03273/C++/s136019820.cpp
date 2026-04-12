#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char a[H][W];
	rep(i,H)rep(j,W) cin >> a[i][j];
	set<int> r, c;
	rep(i,H) r.insert(i);
	rep(j,W) c.insert(j);
	bool can_erase_r = true, can_erase_c = true;

	while (can_erase_r || can_erase_c) {
		vector<int>v_removed;
		for (int i : r) {
			bool flag = true;
			for (int j : c) {
				if (a[i][j] == '#') {
					flag = false; break;
				}
			}
			if (flag) v_removed.push_back(i);
		}
		if (v_removed.size() == 0) can_erase_r = false;
		for (int i : v_removed) r.erase(i);
		v_removed.clear();

		for (int j : c) {
			bool flag = true;
			for (int i : r) {
				if (a[i][j] == '#') {
					flag = false;	break;
				}
			}
			if (flag) v_removed.push_back(j);
		}
		if (v_removed.size() == 0) can_erase_c = false;
		for (int j : v_removed) c.erase(j);
	}

	for (int i : r) {
		for (int j : c) cout << a[i][j];
		cout << endl;
	}

	return 0;
}