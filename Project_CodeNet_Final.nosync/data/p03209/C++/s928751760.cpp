#include <iostream>
#include <math.h>
using namespace std;

int64_t Calc_Target(int64_t n, int64_t t)
{
	int64_t ans = 0;
	int64_t tick = 0;
	// 厚さの計算
	tick = 4 * pow(2, n) - 3;

	if (n == 0)
	{
		if (t > 0)
		{
			ans = 1;
		}
	}
	else
	{
		if (((tick + 1) / 2) <= t)
		{
			// 指定場所が厚さの1/2より大きければひとつ下のレベルのパティはまるまる食べることができる
			ans = (pow(2, n + 1 - 1) - 1) + 1 + Calc_Target(n - 1, t - (tick + 1) / 2);
		}
		else
		{
			// 指定場所が厚さの1/2より小さい時はひとつ下のレベルで再計算
			ans = Calc_Target(n - 1, t - 1);
		}
	}
	return(ans);
}


int main()
{
	int64_t N, X;
	int64_t ans = 0;

	cin >> N >> X;

	if (N > 0)
	{
		ans = Calc_Target(N, X);
	}

	cout << ans << endl;
	
	return(0);
}
