#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <complex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>

#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
#define int ll

using namespace std;
typedef long long ll;
typedef long double ld;


signed main() {
	#ifdef PC
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif	

	int w, h;
	cin >> w >> h;

	int cnt = (w + h - 2);
	vector<vector<int>> matrix(w, vector<int> (h, 0));
	int was = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			char c;
			cin >> c;
			if(c == '#')
				matrix[i][j] = 1, was++;
			else
				matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < (1 << cnt); i++) {
		vector<int> steps;
		int ic = i;
		for(int j = 0; j < cnt; j++) {
			steps.pb(ic % 2);
			ic /= 2;
		}	
		pair<int, int> now = {0, 0};
		bool flag = 0;
		int was1 = 0;
		if(matrix[0][0]) 
			was1++;
		for (int j = 0; j < cnt; j++) {
			if(steps[j] == 1) 
				now.ft++;
			else
				now.sc++;
			if(now.ft >= w || now.sc >= h) {
				flag = 1;
				break;
			}
			if(matrix[now.ft][now.sc]) 
				was1++;
		}
		if(was1 == was && !flag) {
			cout << "Possible" << endl;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}