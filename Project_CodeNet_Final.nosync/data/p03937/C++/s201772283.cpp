//============================================================================
// Name        : Undead2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <istream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
//#include <unordered_map>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#define pb push_back
#define mp make_pair
#define ll long long
#define INF 1000000000
#define EPS 1e-6
#define EPS2 1e-8
using namespace std;

int n,m;
int cnt;

int main()
{
	cin >> n >> m;
	string s;
	for (int i = 0; i<n; ++i)
	{
		cin >> s;
		for (int j = 0; j<m; ++j)
		{
			if (s[j] == '#')
				cnt++;
		}
	}
	if (cnt == n+m-1)
	{
		cout << "Possible";
	} else {
		cout << "Impossible";
	}
}
