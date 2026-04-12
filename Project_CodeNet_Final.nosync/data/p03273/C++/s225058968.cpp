#include <iostream>
#include <vector>
#define rep(i,s,N) for(int i=s;i<N;i++)
using namespace std;

int main(void)
{
	int H, W; cin >> H >> W;
	vector<bool> h(H, false), w(W, false);
	vector<vector<char>> a(H, vector<char>(W));

	rep(i, 0, H) {
		rep(j, 0, W) {
			cin >> a.at(i).at(j);
			if (a.at(i).at(j) == '#')h[i] = true;
		}
	}
	rep(j, 0, W) {
		rep(i, 0, H) {
			if (a.at(i).at(j) == '#')w[j] = true;
		}
	}

	rep(i, 0, H) {
		rep(j, 0, W) {
			if (h[i] && w[j])cout << a.at(i).at(j);
		}
		if (h[i])cout << endl;
	}
	if (!h[h.size()-1])cout << endl;

	return 0;
}