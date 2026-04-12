#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int h, w;
	char a[100][101];
	bool fx[100], fy[100];

	cin >> h >> w;

	for (int i = 0; i < h; i++)
		cin >> a[i];

	memset(fx, 0, 100);
	memset(fy, 0, 100);

	for (int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++)
			if (a[i][j] == '#') {
				fy[i] = 1;
				break;
			}
	}

	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++)
			if (a[i][j] == '#') {
				fx[j] = 1;
				break;
			}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (fy[i] && fx[j])
				cout << a[i][j];
		}
		if(fy[i])
			cout << endl;
	}

	return 0;
}
