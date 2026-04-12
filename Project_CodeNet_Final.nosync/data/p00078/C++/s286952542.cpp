#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int squ[20][20];
	int n, fi, x, y;
	while (cin >> n, n){
		fi = 0;
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				squ[i][j] = 0;
			}
		}
		for (int i = 0; i < n * n; i++){
			if (fi == 0) {
				x = (n / 2);
				y = (n / 2) + 1;
				fi = 1;
			}
			else {
				x += 1;
				y += 1;
				if (x == n) x = 0;
				if (y == n) y = 0;
				if(squ[x][y] >= 1){
					x -= 1;   
					y += 1;
					if (x == -1) x = n - 1; 
			   if (y == n) y = 0;
			 }
			}
			squ[x][y] = i + 1;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				printf("%4d", squ[j][i]);
				// cout << squ[j][i];
				// if (!(j == n - 1)) cout << " ";
			}
			cout << endl;
		}
	}
	return (0);
}