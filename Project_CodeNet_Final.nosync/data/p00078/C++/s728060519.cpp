#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;


const double EPS = 1e-9;
const double PI = 3.14159265359;

const int SIZE = 18;

int main(){

	int n;
	while(cin >> n, n){
		int table[SIZE][SIZE] = {0};
		int num = 1;
		int x = n/2;
		int y = n/2+1;
		table[y++][x++] = num++;
		while(num <= n*n){
			x%=n;
			y%=n;
			if(table[y][x] != 0){
				x+=n-1;
				y++;
			}else{
				table[y++][x++] = num++;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%4d", table[i][j]);
			}
			cout << endl;
		}
	}

	return 0;
}