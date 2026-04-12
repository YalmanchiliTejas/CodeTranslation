#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define pb(a) push_back(a)
#define MAX(a, b) ((a < b)?b:a)
#define MIN(a, b) ((a > b)?b:a)
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

ull gcd(ull a, ull b) { return b ? gcd(b, a%b) : a; }
ull lcm(ull m, ull n) {	return ((0 == m) || (0 == n)) ? 0 : ((m / gcd(m, n)) * n); }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int cost = 0;
	int xymin = MIN(x, y);

	// cピザの枚数
	if ( a + b > 2 * c )
	{
		// cピザを買ったほうが良い
		cost += xymin * 2 * c;
		x -= xymin;
		y -= xymin;
	}

	if ( a > 2 * c )
	{
		cost += x * 2 * c;
	}
	else
	{
		cost += x * a;
	}

	if ( b > 2 * c )
	{
		cost += y * 2 * c;
	}
	else
	{
		cost += y * b;
	}

	cout << cost << endl;


	return 0;
}
