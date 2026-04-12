#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
typedef unsigned long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)
# define _sort(arg) sort(begin(arg), end(arg))

/*
string level_burgur(int n)
{
	if (n == 0)
	{
		return "P";
	}
	string burgur = "B" + level_burgur(n-1) + "P" + level_burgur(n-1)+"B";
	return burgur;
}
*/

ll ret_size(ll remain, ll n)
{
	/*
	if (remain == 0)
	{
		return 0;
	}
	*/
	//ll tmo = 1 << 52;
	//ll tmp_ = tmo - 3;
	//cout << tmp_ << endl;
	//printf("%llu\n", (1 << 52) - 3);
	if (n == 0)
	{
		if (remain != 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
	ll tmo = 1ull << (n+2);
	ll tmp = tmo - 3;
	//cout << "test n+2=" << n+2 << "; tmp=" << tmp << "; remain="<<remain << endl;
	ll half = ((tmp + 1) >> 1);

	if (remain < half)
	{
		if (remain > 0)
		{
			//cout << "left" << endl;
			return ret_size(remain - 1, n-1);
		}
		else
		{
			return 0;
		}
		
	}
	else if (remain == half)
	{
		//cout << "e" << endl;
		return (1ull << n);
	}
	else
	{
		//cout << "r" << endl;
		return (1ull << n) + ret_size(remain - half, n-1);
	}
}

int main()
{
	cin.tie(NULL);
	//ios::sync_with_stdio(false);

	ll N, X;

	cin >> N >> X;

	//cout << sizeof(ll) << endl;
	/*
	string pan = level_burgur(N);

	ll total = 0;
	for (ll i = 0; i < X; i++)
	{
		if (pan[i] == 'P')
		{
			total++;
		}
	}

	*/

	ll total = ret_size(X, N);

	//printf("%llu\n", total);
	cout << total << endl;

	return 0;
}