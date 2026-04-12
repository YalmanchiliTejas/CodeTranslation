#include <iostream>
#include <sstream>
#include <stdio.h>
//#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;


int main(void)
{
	int H, W; cin >> H >> W;
	vector<string> A(H); rep(i, 0, H)cin >> A[i];
	int cnt = 0;
	rep(i, 0, H) {
		rep(j, 0, W) {
			if (A[i][j] == '#')cnt++;
		}
	}
	if (cnt == H + W - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}
