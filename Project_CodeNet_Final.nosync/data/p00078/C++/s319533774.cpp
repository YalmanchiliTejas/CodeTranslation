#include <iostream>
#include <iomanip>

using namespace std;

void init(int s[][15], int n)
{
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) s[i][j] = 0;
	}
}

void show(int s[][15], int n)
{
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) cout << setw(4) << s[i][j];
		cout << endl;
	}
}

int main()
{
	int n;
	int square[15][15];
	while (true) {
		cin >> n;
		if (n==0) break;
		
		init(square, n);
		
		int x = n/2;
		int y = n/2 + 1;
		for (int i=1; i<n*n; i++) {
			square[y][x] = i;
			x = (x+1) % n; y = (y+1) % n;
			while (square[y][x] > 0) { x = (x+n-1) % n; y = (y+1) % n; }
		}
		square[y][x] = n*n;
		show(square, n);
	}
	
	return 0;
}