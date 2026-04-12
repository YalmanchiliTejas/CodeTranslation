#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C, X, Y;
	
	cin >> A >> B >> C >> X >> Y;

	int total = 0;

	if (A+B >= 2 * C)
	{
		if (X >= Y)
		{
			if (A <= 2 * C)
			{
				total += 2 * Y * C;
				total += (X-Y)*A;
			}
			else
			{
				total = 2 * X * C;
			}
			
		}
		else
		{
			if (B <= 2 * C)
			{
				total += 2 * X * C;
				total += (Y-X)*B;
			}
			else
			{
				total = 2 * Y * C;
			}
			
		}
	}
	else
	{
		total += X * A + Y * B;
	}
	
	cout << total << endl;

	return 0;
}
