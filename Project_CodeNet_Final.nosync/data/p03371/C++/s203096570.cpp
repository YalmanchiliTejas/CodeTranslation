#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>
#include <iomanip>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define eps (1e-15)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;


int main()
{
#ifdef LOCAL_MACHINE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int a, b, c;
	int x, y;
	cin >> a >> b >> c;
	cin >> x >> y;
	int res = a * x + b * y;
	if (c * 2 > a + b)
	{
		cout << res;
		return 0;
	}
	
	for (int i = 0; i < (x + y) * 2; i++)
	{
		int curx = x, cury = y;
		int curres = i * c;
		curx -= i / 2;
		cury -= i / 2;
		if (curx > 0)
			curres += curx * a;
		if (cury > 0)
			curres += cury * b;
		res = min(curres, res);
	}
	cout << res;
	return 0;
}