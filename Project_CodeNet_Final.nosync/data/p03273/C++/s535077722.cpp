#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int h, w;
	cin >> h >> w;
	
	vector<string> a(h);
	for(int i = 0; i < h; ++i) {
		cin >> a[i];
	}
	
	vector<bool> row(h, false);
	vector<bool> colum(w, false);
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if( a[i][j] == '#' ) {
				row[i] = true;
				colum[j] = true;
			}
		}
	}
	
	for(int i = 0; i < h; ++i) {
		if( row[i] ) {
			for(int j = 0; j < w; ++j) {
				if( colum[j] ) cout << a[i][j];
			}
			
			cout << endl;
		}
	}
	
	return 0;
}
