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
	int N, K;
	string S;
	cin >> N >> S >> K;
	char A = S[K-1];
	for (int i = 0; S[i]; i++)
	{
		if (S[i] == A)
			cout << S[i];
		else
			cout << "*";
	}
	cout << endl;
}

