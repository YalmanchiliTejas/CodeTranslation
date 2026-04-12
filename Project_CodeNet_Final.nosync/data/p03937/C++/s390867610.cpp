#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using Pos = pair<int, int>;
bool solve() {
	int H, W;
	cin >> H >> W;
	vector<string> A(H);
	for (string& S : A) cin >> S;
	Pos current(0, 0);
	vector<Pos> passed = { current };
	vector<int> dh = { 1, 0 }, dw = { 0, 1 };
	while (current != Pos(H - 1, W - 1)) {
		bool loop = false;
		for (int i = 0; i < 2; i++) {
			int h = current.first + dh[i], w = current.second + dw[i];
			if (h >= H || w >= W) continue;
			if (find(passed.begin(), passed.end(), Pos(h, w)) != passed.end()) continue;
			if (A[h][w] == '#') {
				loop = true;
				current = Pos(h, w);
				passed.push_back(current);
				break;
			}
		}
		if (!loop) break;
	}
	size_t hash_cnt = 0;
	for (string S : A) for (char c : S) if (c == '#') hash_cnt++;
	return (passed.size() == hash_cnt);
}
int main() {
	cout << (solve() ? "Possible" : "Impossible") << endl;
}