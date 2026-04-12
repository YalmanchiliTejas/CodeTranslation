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
	int a, b, c;
	cin >> a >> b >> c;
	if ((a * 100 + b * 10 + c) % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}