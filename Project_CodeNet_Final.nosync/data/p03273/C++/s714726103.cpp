#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define what_is(x) cerr << #x << " is " << x << endl;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (int i = 0; i < h; i++) cin >> grid[i];

	set<int> h_white, v_white;
	for (int i = 0; i < h; i++) {
		bool white = true;
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '#') {
				white = false;
				break;
			}
		}
		if (white) h_white.insert(i);
	}
	for (int i = 0; i < w; i++) {
		bool white = true;
		for (int j = 0; j < h; j++) {
			if (grid[j][i] == '#') {
				white = false;
				break;
			}
		}
		if (white) v_white.insert(i);
	}

	vector<string> answer;
	for (int i = 0; i < h; i++) {
		if (h_white.count(i)) continue;
		string s;
		for (int j = 0; j < w; j++)
			if (!v_white.count(j)) s.push_back(grid[i][j]);
		answer.push_back(s);
	}
	for (const string& s : answer) cout << s << endl;
}
