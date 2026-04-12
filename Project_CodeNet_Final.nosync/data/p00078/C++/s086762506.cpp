#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

void make(int area[15][15], int &h, int &w, int n, int count){
	h++;
	w++;
	if(h >= n) h = 0;
	if(w >= n) w = 0;
	while(area[h][w]){
		h++;
		w--;
		if(h >= n) h = 0;
		if(w < 0) w = n - 1;
	}
	area[h][w] = count;
}

int main(){
	int n;
	int area[15][15];
	while(cin >> n){
		if(n == 0) break;
		int count = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				area[i][j] = 0;
		int h = n / 2 + 1;
		int w = n / 2;
		area[h][w] = count++;
		do{
			make(area, h, w, n, count);
			count++;
		}while(count <= n * n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << setw(4) << area[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}