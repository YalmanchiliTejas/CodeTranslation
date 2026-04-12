#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <bitset>


int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> a(H, vector<char>(W));
	rep(i, H) {
		rep(j, W) {
			cin >> a.at(i).at(j);
		}	
	}

	vector<bool> existH(H);
	vector<bool> existW(W);

	rep(i, H) {
		rep(j, W) {
			if (a.at(i).at(j) == '#') {
				existH.at(i) = true;
				existW.at(j) = true;
			}
		}
	}

	rep(i, H) {
		if (existH.at(i) == true) {
			rep(j, W) {
				if (existW.at(j) == true) {
					cout << a.at(i).at(j);
				}
			}
			cout << endl;
		}
	}
}