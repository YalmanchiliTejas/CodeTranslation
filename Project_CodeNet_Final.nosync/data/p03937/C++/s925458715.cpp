#include <iostream>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#include <string>
#include <vector>
#include <algorithm>

int main() {

	char mas[9][9];
	rep(i, 9)
		rep(j, 9)
		mas[i][j] = '.';

	int h, w;
	cin >> h >> w;
	rep(i, h)
		cin >> mas[i];
	int cnt=0;
	rep(i, h) {
		if (mas[i + 1][cnt] == '#') {
			mas[i][cnt] = '.';
			continue;
		}
		else if (mas[i][cnt]=='#') {
			mas[i][cnt] = '.';
			i--;
			cnt++;
			continue;
		}
	}
	cnt = 0;
	rep(i, h)
		rep(j, w)
		if (mas[i][j] == '#')
			cnt = 1;
	if (cnt == 1)
		cout << "Impossible" << endl;
	else cout << "Possible" << endl;

}