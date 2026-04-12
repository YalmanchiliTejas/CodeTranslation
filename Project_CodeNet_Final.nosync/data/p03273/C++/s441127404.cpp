#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;

	vector<bool> wc(w, false);
	vector<string> m;
	for (int i = 0; i < h; ++i){
		string s;
		cin >> s;
		bool isContinue = true;
		for (int j = 0; j < w; ++j) {
			if (s[j] == '#') {
				wc[j] = true;
				isContinue = false;
			}
		}
		if (isContinue) {
			continue;
		}
		m.push_back(s);
	}

	for (auto& i : m) {
		for (int j = 0; j < w; ++j) {
			if (wc[j]) {
				cout << i[j];
			}
		}
		cout << endl;
	}


	return 0;
}