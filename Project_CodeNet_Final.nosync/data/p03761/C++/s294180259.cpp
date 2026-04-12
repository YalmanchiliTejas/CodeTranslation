//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include <climits>
#include <cmath>
#include <cstring>

#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;
typedef unsigned long long int ull;


int main()
{
	FAST;
	int n;
	cin >> n;
	string str[n];
	for(int i=0 ; i<n ; i++)
		cin >> str[i];

	int mat[50][26] = {0};

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<str[i].size() ; j++)
			mat[i][str[i][j]-'a']++;
	}

	int ans[26] = {0};
	for(int i=0 ; i<26 ; i++)
	{
		int m = INT_MAX;
		bool flag = false;
		for(int j=0 ; j<n ; j++)
		{
		    if(mat[j][i] == 0)
		        flag = true;
			m = min(m , mat[j][i]);
		}
        if(flag == false)
		ans[i] = m;
	}

	bool flag = false;
	for(int i=0 ; i<26 ; i++)
	{
		if(ans[i] != 0)
			flag = true;

		for(int j=0 ; j<ans[i] ; j++)
			cout << (char)('a'+i);
	}

	if(!flag)
	{
		cout << " ";
	}
	return 0;
}