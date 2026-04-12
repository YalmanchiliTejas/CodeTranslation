
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <queue>

using namespace std;

#define ll long long
#define MOD 1000000007LL


class Main {
public:
	bool isPossible(vector<string> map) {
		int h = map.size();
		int w = map[0].size();
		vector<string> temp = map;

		int x = 0;
		int y = 0;
		temp[y][x] = '.';

		while (!(x == w-1 && y == h-1)) {
			bool isMovableX = (x != w - 1 && map[y][x+1] == '#');
			bool isMovableY = (y != h - 1 && map[y+1][x] == '#');

			if (isMovableX && !isMovableY) {
				x++;
				temp[y][x] = '.';
			}
			else if(!isMovableX && isMovableY) {
				y++;
				temp[y][x] = '.';
			}
			else {
				return false;
			}
		}

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				if (temp[i][j] == '#') {
					return false;
				}
			}
		}

		return true;
	}
};


int main()
{
	Main m;
	int w, h;
	vector<string> map;

	cin >> h >> w;
	for (int i = 0;i < h;i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}

	cout << (m.isPossible(map) ? "Possible" : "Impossible") << endl;

    return 0;
}

