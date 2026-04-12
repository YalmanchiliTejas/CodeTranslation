#include <iostream>
#include <vector>

using namespace std;

int main() {
	int H, W;
	vector<vector<char>> map;

	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		map.push_back(vector<char>());
		for (int j = 0; j < W; j++) {
			char tmp;
			cin >> tmp;
			map[i].push_back(tmp);
		}
	}

	int j;
	//行消去操作
	for (int i = 0; i < map.size(); i++) {
		for (j = 0; j < W; j++) {
			if (map[i][j] == '#')
				break;
		}
		if (j == W) {
			map.erase(map.begin() + i);
			i--;
		}
	}

	//列消去操作
	for (int i = 0; map.size() > 0 && i < map[0].size(); i++) {
		for (j = 0; j < map.size(); j++) {
			if (map[j][i] == '#')
				break;
		}
		if (j == map.size()) {
			for (int k = 0; k < map.size(); k++)
				map[k].erase(map[k].begin() + i);
			i--;
		}
	}

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}