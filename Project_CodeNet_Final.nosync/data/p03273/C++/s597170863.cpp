#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;
int H, W;

void compress_row(string& s)
{
	int i;
	for (i = 0; i < (int)s.size(); i++) {
		if (s[i] == '#') {
			return;
		}
	}

	for (i = 0; i < (int)s.size(); i++) {
		s[i] = '-';
	}
}

bool compress() {

	bool dirty = false;
	auto it = vec.begin();
	while (it != vec.end()) {
		compress_row(*it);
		++it;
	}

	int i;
	for (i = 0; i < W; i++) {
		bool able = true;
		int j;
		for (j = 0; j < (int)vec.size(); j++) {
			if (vec[j][i] == '#') {
				able = false;
				break;
			}
		}	

		if (!able) {
			continue;
		}

		dirty = true;
		for (j = 0; j < (int)vec.size(); j++) {
			vec[j][i] = '-';
		}
	}

	return dirty;
}

int main(void) {
	cin >> H >> W;

	string s;
	for (int i = 0; i < H; i++) {
		cin >> s;
		vec.push_back(s);
	}

	compress();

	for (int i = 0; i < H; i++) {
		bool out = false;
		for (int j = 0; j < W; j++) {
			if (vec[i][j] != '-') {
				cout << vec[i][j];
				out = true;
			}
		}
		if (out) {
			cout << endl;
		}
	}

	return 0;
}
