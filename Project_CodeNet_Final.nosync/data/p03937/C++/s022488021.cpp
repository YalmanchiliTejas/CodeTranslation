#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int main() {
	int h, w;
	cin >> h >> w;
	char a[10][10];
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#')cnt++;
		}
	}
	if (cnt == h + w - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}