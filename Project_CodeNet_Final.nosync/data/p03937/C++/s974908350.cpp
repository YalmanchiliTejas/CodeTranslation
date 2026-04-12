#include <iostream>
#include <cstdio>
#define N 10
using namespace std;

int h, w, c;
string a[N];
int main()
{
	int i, j;
	cin >> h >> w;
	for (i = 0; i < h; i++) {
		cin >> a[i];
		for (j = 0; j < w; j++) c += a[i][j] == '#';
	}
	if (c != h + w - 1) cout << "Impossible";
    else cout << "Possible" << endl;
    return 0;
}