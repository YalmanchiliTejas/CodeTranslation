#include<iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)



signed main()
{
	int r, g, b;
	cin >> r >> g >> b;
	int tmp = 100 * r + 10 * g + b;
	if (tmp % 4 == 0) cout << "YES" << endl;
	else  cout << "NO" << endl;
}