#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
signed main() {
	int H, W; cin >> H >> W;
	int U = 0;
	vector<vector<char>> vec(H, vector<char>(W));
	for (int X = 0; X < H; X++) {
		for (int Y = 0; Y < W; Y++) {
			cin >> vec[X][Y];
			if (vec[X][Y] == '#') {
				U++;
			}
		}
	}
	if (U == H + W - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}