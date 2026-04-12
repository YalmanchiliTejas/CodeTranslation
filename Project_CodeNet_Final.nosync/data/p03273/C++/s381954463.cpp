#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int H , W;

	cin >> H >> W;
	vector<string> a;

	for (int i = 0; i < H;i++) {
		string s;
		cin >> s;
		bool is_space = true;
		for (char c : s) {
			if (c == '#') {
				is_space = false;
				break;
			} 
		}
		if (is_space == true) {
			continue;
		}
		a.push_back(s);
	}

	int new_h = a.size();

	vector<string> result(new_h);

	for(int x = 0; x < W; x++) {
		bool is_space = true;
		for (int y = 0; y < new_h; y++) {
			if (a[y].at(x) =='#') {
				is_space = false;
				break;
			}
 
		}
		if (is_space == true) {
			continue;
		}
		for (int y = 0; y < new_h; y++) {
			result[y] += a[y].at(x);
		}

	}

	for (int y = 0; y < new_h; y++) {
		cout << result[y] << endl;
	}

	return 0;
}