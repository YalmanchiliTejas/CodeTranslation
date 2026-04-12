#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cmath>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)

const int INF = 100000000;

using namespace std;


int main() {
	int n;
	cin >> n;
	cout << 800 * n - (n / 15) * 200 << endl;

	return 0;
}