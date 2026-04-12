#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll a, b, ab, an, bn;
	cin >> a >> b >> ab >> an >> bn;

	ll res{0};
	if (an == bn)
	{
		if (a + b < ab*2)
			res = an*a + bn*b;
		else
			res = ab*2*an;
	}
	else
	{
		if (a + b < ab*2)
			res = an*a + bn*b;
		else
		{
			ll abn = min(an, bn);
			//std::cout << "abn : " << abn*2 << std::endl;
			res += abn*ab*2;

			an -= abn, bn -= abn;
			if (an != 0)
			{
			//	std::cout << "an : " << an << std::endl;
				res += min(a*an, ab*2*an);
			}
			else
			{
				res += min(b*bn, ab*2*bn);
			}
		}
	}
	std::cout << res << std::endl;
}
