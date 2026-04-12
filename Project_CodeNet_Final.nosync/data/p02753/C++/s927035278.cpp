// To the MOTHER OF DRAGONS

#include <bits/stdc++.h>
#define ll long long int
#define llu unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.14159265358979323846
#define RAGE ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

void solve()
{
	string s;
	cin >> s;
	for(ll i = 0; i < s.length() - 1; i++)
	{
		if(s[i] != s[i + 1])
		{
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main()
{
	RAGE
	ll t;
	//cin >> t;
	//while(t--)
		solve();
	return 0;
}
