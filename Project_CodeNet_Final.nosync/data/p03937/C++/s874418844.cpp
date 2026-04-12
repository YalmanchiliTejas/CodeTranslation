#include <iostream>

using namespace std;

#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;


int main()
{
	int h, w;
	cin >> h >> w;
	char a[h][w];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h-1; i++) {
		for (int j = 0; j < w-1; j++) {
			if (a[i][j+1] == '#') {
				for (int k = i+1; k < h; k++) {
					// cout << "1: " << k << " " << j << "\n";
					// cout << a[k][j] << "\n";
					if (a[k][j]=='#') {
						cout << "Impossible" << "\n";
						return 0;
					}
				}
			}
			if (a[i+1][j] == '#') {
				for (int k = j+1; k < w; k++) {
					if (a[i][k]=='#') {
//						cout << i+1 << " " << k << "\n";
						cout << "Impossible" << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "Possible" << "\n";
}
