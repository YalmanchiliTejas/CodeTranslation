#include <iostream>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#include <string>
#include <vector>
#include <algorithm>
#include <map>
//long int dp[1001][1001];


int main() {
	vector<string> s(8);
	int h, w, cnt=0;
	cin >> h >> w;
	rep(i, h)
		cin >> s[i];
	rep(i, h)
		rep(j, w)
		if (s[i][j] == '#')
			cnt++;
	h+w - 1 == cnt ? cout << "Possible" << endl : cout << "Impossible" << endl;
}