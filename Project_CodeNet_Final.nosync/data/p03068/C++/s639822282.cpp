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

	int N,K;
	string S;
	cin >> N;
	cin >> S;
	cin >> K;
	char t = S[K-1];

	rep(i, N)
	{
		if (S[i]!=t)
		{
			cout << "*";
		}
		else
		{
			cout << t;
		}
		
	}
	cout << endl;

	
	return 0;
}
