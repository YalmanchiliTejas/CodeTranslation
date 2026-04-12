#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int AB = C * 2;
	int ans = 0;
	while (X > 0 || Y > 0)
	{
		if ((X > 0 && Y > 0) && AB < A+B)
		{
			ans += AB;
			X--;
			Y--;
		}
		else if (X > 0 && Y > 0)
		{
			ans += min(A, AB);
			ans += min(B, AB);
			X--;
			Y--;
		}
		else if (X > 0)
		{
			ans += min(A, AB);
			X--;
		}
		else
		{
			ans += min(B, AB);
			Y--;
		}
	}
	cout << ans << endl;
}

