#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> transpose(vector<string> a)
{
	const int h = a.size();
	const int w = a[0].size();
	vector<string> t(w, string(h, '*'));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			t[j][i] = a[i][j];
		}
	}
	return t;
}

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	for (auto& s : a) {
		cin >> s;
	}

	string w1(a[0].size(), '.');
	a.erase(remove(a.begin(), a.end(), w1), a.end());

	a = transpose(a);
	string w2(a[0].size(), '.');
	a.erase(remove(a.begin(), a.end(), w2), a.end());

	a = transpose(a);
	for (auto& s : a) {
		cout << s << endl;
	}
}
