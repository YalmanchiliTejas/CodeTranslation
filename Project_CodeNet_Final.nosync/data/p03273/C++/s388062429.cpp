#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <complex>
#define full(c) c.begin(), c.end()
#define vector2d(name,type,h,w,init) vector<vector<type>> name(h,vector<type>(w,init)) 
const int PRIME = 1000000007;
const int INF = 2147483647;
const double PI = 3.14159265358979323846;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int k, i, j, h, w, cnt;
	cin >> h >> w;
	vector2d(mp, char, h, w, 0);
	vector2d(flag, bool, h, w, false);
	for (i = 0; i < h; i++){
		string tmp;
		cin >> tmp;
		for (j = 0; j < w; j++) mp[i][j] = tmp[j];
	}
	for (k = 0; k < h; k++){
		for (i = 0; i < w; i++){
			if (mp[k][i] == '#') break;
		}
		if (i == w){
			for (i = 0; i < w; i++){
				flag[k][i] = true;
			}
		}
	}
	for (k = 0; k < w; k++){
		for (i = 0; i < h; i++){
			if (mp[i][k] == '#') break;
		}
		if (i == h){
			for (i = 0; i < h; i++){
				flag[i][k] = true;
			}
		}
	}
	for (i = 0; i < h; i++){
		cnt = 0;
		for (j = 0; j < w; j++){
			if (flag[i][j] == false){
				cout << mp[i][j];
				cnt++;
			}
		}
		if (cnt != 0) cout << endl;
	}
	return 0;
}
