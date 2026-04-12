
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <algorithm> 
#include <string>

#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
#define sum(n) accumulate((n).begin(), (n).end(), 0)
using namespace std;


int main(){
	int h, w,check,outcheck;
	char cell[100][100];
	bool is_space_w[100], is_space_h[100];

	check = 0;
	outcheck = 0;

	rep(i, 100) {
		is_space_w[i] = false;
		is_space_h[i] = false;

	}
	
	cin >> h >> w;

	rep(i, h) {
		rep(j, w) {
			cin >> cell[i][j];
		}
	}

	rep(i, h) {
		check = 0;
		rep(j, w) {
			if (cell[i][j] == '.') {
				check++;
			}
			
		}

		if(check == w) {
			is_space_h[i] = true;
		}
		
	}

	rep(i, w) {
		check = 0;
		rep(j, h) {
			if (cell[j][i] == '.') {
				check++;
			}
			
		}

		if (check == h) {
			is_space_w[i] = true;
		}
	}
	cout << endl;

	rep(i, h) {
		outcheck = 0;
		rep(j, w) {
			if (!(is_space_w[j] || is_space_h[i])) {
				cout << cell[i][j];
				outcheck++;
			}
		}
		if (outcheck != 0) {
			cout << endl;
		}
		
	}

}