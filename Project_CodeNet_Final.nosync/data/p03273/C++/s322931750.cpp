#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> mp(h);
	for (int i = 0; i < h; i++) {
		cin >> mp[i];
	}

	vector<string> mp2;

	for (int i = 0; i < h; i++) {
		bool hh = false;
		for (int j = 0; j < w; j++) {
			if (mp[i][j] != '.') {
				hh = true;
			}
		}
		if (hh) {
			mp2.push_back(mp[i]);
		}
	}

	vector<string> mp3;

	for (int i = 0; i < w; i++) {
		string s = "";
		bool hh = false;
		for (int j = 0; j < mp2.size(); j++) {
			if (mp2[j][i] != '.') {
				hh = true;
			}
			s += mp2[j][i];
		}
		if (hh) {
			mp3.push_back(s);
		}
	}

	vector<string> mp4;
	for (int i = 0; i < mp3[0].size(); i++) {
		string s = "";
		for (int j = 0; j < mp3.size(); j++) {
			s += mp3[j][i];
		}
		mp4.push_back(s);
	}

	for (int i = 0; i < mp4.size(); i++) {
		cout << mp4[i] << endl;
	}

	return 0;
}