#include<iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;
int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);

	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	vector<bool> row(h, false);
	vector<bool> col(w, false);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] != '.') row[i] = true;
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (s[j][i] != '.') col[i] = true;
		}
	}
	
	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0; j < w; j++) {
				if (col[j]) cout << s[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}