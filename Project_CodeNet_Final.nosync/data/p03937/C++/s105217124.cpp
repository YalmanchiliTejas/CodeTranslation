#include <iostream>

using namespace std;
int main(void) {
	int H, W;
	cin >> H >> W;

	int correct = H + W - 1;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		char tmp[8];
		cin >> tmp;
		for (int j = 0; j < W; j++) {
			if (tmp[j] == '#') cnt++;
		}
	}
	if (cnt == correct) cout << "Possible";
	else cout << "Impossible";
	cout << endl;
	return 0;
}
