#include <iostream>
#include <string>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;

	string s;
	int sum = 0;
	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '#') {
				sum++;
			}
		}
	}
	cout << (sum == h + w - 1 ? "Possible" : "Impossible") << endl;

	return 0;
}