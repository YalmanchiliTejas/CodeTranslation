#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cstdio>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s;
	int a, d;

	cin >> a >> s >> d;

	auto c = s[d - 1];

	for (auto& ss : s)
	{
		ss = (c == ss ? c : '*');
	}

	cout << s << endl;
}