//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;

int main() {
	int h, w;
	cin >> h >> w;
	VI highsum(h+1);
	VI weisum(w+1);
	VS a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.')highsum[i]++;
			else if (a[i][j] == '#')highsum[i] += 2;
		}
	}
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (a[i][j] == '.')weisum[j]++;
			else if (a[i][j] == '#')weisum[j] +=2 ;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (highsum[i] == w) continue;
			if (weisum[j] == h) continue;
			cout << a[i][j];
		}
		if(highsum[i]!=w) cout << "\n";
	}
	return 0;
}
