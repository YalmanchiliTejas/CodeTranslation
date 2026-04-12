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
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int h, w;
	cin >> h >> w;
	
	vector<string> a(h);
	for(int i = 0; i < h; ++i) {
		cin >> a[i];
	}
	
	vector< vector<int> > last(h);
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if( a[i][j] == '#' ) last[i].push_back(j);
		}
		
		if( last[i].size() == 0 ) last[i].push_back(100);
	}
	
	for(int i = 0; i < h - 1; ++i) {
		if( last[i].back() != 100 ) {
			if( last[i].back() > last[i + 1].front() ) {
				cout << "Impossible" << endl;
				return 0;
			}
		} else {
			if( last[i + 1].front() != 100 ) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	
	for(int i = 0; i < h - 1; ++i) {
		for(int j = 0; j < w - 1; ++j) {
			if( a[i][j] == '.') continue;
			
			if( a[i][j] == '#' ) {
				if( (a[i][j + 1] == '.' && a[i + 1][j] == '.') 
					|| (a[i][j + 1] == '#' && a[i + 1][j] == '#' && a[i + 1][j + 1] == '#' ) ) {
					cout << "Impossible" << endl;
					return 0;
				}
			}				
		}
	}
	
	cout << "Possible" << endl;
	
	return 0;
}
