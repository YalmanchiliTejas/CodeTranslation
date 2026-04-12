
#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<vector>
#include<math.h>
#include<climits>
#include<map>

using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll x;
	cin >> x;
	if (x >= -40 && x <= 40)
	{
		if (x >= 30)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}

}

