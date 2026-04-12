#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

int		main(void)
{
	string S;
	cin >> S;
	if (S[0] == S[1] && S[1] == S[2])
		puts("No");
	else
		puts("Yes");
}
