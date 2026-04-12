#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int main() {
	int h, w;
	cin >> h >> w;
	vector<int> vec, vec1;
	string s[100];
	for (int i = 0; i < h; i++) {
		cin >> s[i];
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				vec.emplace_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (s[vec[j]][i] == '#') {
				vec1.emplace_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec1.size(); j++) {
			cout << s[vec[i]][vec1[j]];
		}
		cout << endl;
	}
	return 0;
}

