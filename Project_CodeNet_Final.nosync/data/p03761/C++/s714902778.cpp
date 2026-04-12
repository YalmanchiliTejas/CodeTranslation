#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

int main()
{
	ll n;
	cin >> n;
	vector<string> s(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	string ans;
	for (char i = 'a'; i < 'z' + 1; i++)
	{
		ll num = 50;
		for (ll j = 0; j < n; j++)
		{
			ll cnt = 0;
			for (ll k = 0; k < s[j].length(); k++)
			{
				if (s[j][k] == i) cnt++;
			}
			num = min(cnt, num);
		}
		for (ll j = 0; j < num; j++)
		{
			ans += i;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}