#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
using namespace std;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = 0;
	if (A+B<=2*C)
	{
		ans = A * X + B * Y;
	}
	else
	{
		if (X>=Y)
		{
			ans += 2* C * Y;
			ans += min(A * (X - Y), 2 * C * (X - Y));
		}
		else
		{
			ans += 2 * C * X;
			ans += min(B * (Y - X), 2 * C * (Y - X));
		}
	}
	co(ans);
}