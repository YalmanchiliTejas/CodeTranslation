#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <set>
#include <map>
//#include <bits/stdc++.h>

#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
#define ll long long
#define bl bool
#define nn printf("\n");
#define mod 1000000007

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<char> right = { 'p', 'o', 'i', 'u', 'y', 'l', 'k', 'j', 'h', 'm', 'n' };
	
	while (1)
	{
		string str; cin >> str;
		vector<int> move((int)str.size() + 5, 0);
		int cnt = 0;
		if (str[0] == '#') { return 0; }
		rep(i, (int)str.size())
		{
			if (count(all(right), str[i]) > 0){ move[i] = 1;	}
		}
		for (int i = 1; i < (int)str.size(); i++)
		{
			if (move[i - 1] != move[i]){ cnt += 1; }
		}
		printf("%d\n", cnt);
	}
	return 0;
}