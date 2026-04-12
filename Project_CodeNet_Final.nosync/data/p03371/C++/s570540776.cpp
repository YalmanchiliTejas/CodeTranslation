#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	lint A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	lint ans = INF64;

	ans = min(ans, A * X + B * Y);
	ans = min(ans, C * max(X, Y) * 2);
	if (X < Y)
		ans = min(ans, C * X * 2 + (Y - X) * B);
	else
		ans = min(ans, C * Y * 2 + (X - Y) * A);

	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}