#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll unsigned long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int mod = 1e9 + 7;
int main()
{
	SPEED
	string s;
	cin >> s;

	if (s[0] == 'A' && s[1] == 'A' && s[2] == 'A')
	{
		cout << "No";
	}
	else if (s[0] == 'B' && s[1] == 'B' && s[2] == 'B')
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
	
	return 0;
}