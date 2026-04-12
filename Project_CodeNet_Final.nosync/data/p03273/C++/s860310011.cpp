#include<iostream>
#include<string>
#include<complex>
#include<vector>
#include<algorithm>
#include<functional>
#include<array>
#include<map>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF 1e+9


int main() {
	int h, w;
	bool white = true;
	cin >> h >> w;
	char a[101][101];
	for (int i = 0; i < h; i++) {
		white = true;
		for (int j = 0; j < w; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '#') white = false;
		}
		if (white == true)
			for (int j = 0; j < w; j++) a[i][j] = 'n';
	}


	for (int i = 0; i < w; i++) {
		white = true;
		for (int j = 0; j < h; j++)
		{
			
			if (a[j][i] == '#') white = false;
		}
		if (white == true)
			for (int j = 0; j < h; j++) a[j][i] = 'n';
	}

	for (int i = 0; i < h; i++) {
		white = true;
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == '#') white = false;
			if (a[i][j] != 'n') cout << a[i][j];
		}
		if(white==false) cout << endl;
	}

	return 0;
}