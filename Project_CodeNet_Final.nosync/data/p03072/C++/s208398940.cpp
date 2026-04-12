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

	int N;
	
	cin >> N;

	int H[N];

	int max_ = 0;
	int count = 0;
	rep(i, N)
	{
		cin >> H[i];
		if (H[i] >= max_ )
		{
			count++;
		}
		max_ = max(H[i], max_);
	}

	cout << count << endl;

	
	return 0;
}
