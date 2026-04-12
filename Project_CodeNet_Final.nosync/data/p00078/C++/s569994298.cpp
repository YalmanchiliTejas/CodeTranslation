#include <iostream>
using namespace std;

int n;
int sq[15][15];

int main(){
    while (1){
	cin >> n;
	if (n == 0) break;
	int mid = n / 2;
	int m = 1;
	int x = mid+1, y = mid;

	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
		sq[i][j] = 0;
	    }
	}

	while (m <= n*n){
	    if (sq[x%n][y%n] == 0) sq[x%n][y%n] = m;
	    else {
		while (sq[x%n][y%n] != 0){
		    x++; y--;
		}
		sq[x%n][y%n] = m;
	    }
	    x++; y++;
	    m++;
	}
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
		printf("%4d", sq[i][j]);
	    }
	    cout << endl;
	}
    }
}