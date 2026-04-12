#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <set>
#define MAX 100000
#define rep(i,s,N) for(int i=s;i<N;i++)
using namespace std;
typedef long long int lli;

int main(void)
{
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int half = min(x, y);
	int sum = half * min(a + b, 2 * c);
	sum += min((x - half)*a + (y - half)*b, (x + y - 2 * half) * 2 * c);
	cout << sum << endl;

	return 0;
}