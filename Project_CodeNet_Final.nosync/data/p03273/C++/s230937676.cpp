//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;
typedef unsigned long long int ull;


int main()
{
	FAST;
	string str[101];
	int r,c;
	cin >> r >> c;

	for(int i=0 ; i<r ; i++)
		cin >> str[i];


	for(int i=0 ; i<r ; i++)
	{
		bool flag = false;
		for(int j=0 ; j<c ; j++)
		{
			if(str[i][j] == '#' )
				flag = true;
		}

		if(!flag)
		{
			for(int j=0 ; j<c ; j++)
			{
				str[i][j] = '1';
			}
		}
	}

	for(int i=0 ; i<c ; i++)
	{
		bool flag = false;
		for(int j=0 ; j<r ; j++)
		{
			if(str[j][i] == '#')
				flag = true;
		}

		if(!flag)
		{
			for(int j=0 ; j<r ; j++)
				str[j][i] = '1';
		}
	}

	for(int i=0 ; i<r ; i++)
	{
		bool flag = true;
		for(int j=0 ; j<c ; j++)
		{
			if(str[i][j] != '1')
			{
				flag = false;
				cout << str[i][j];
			}
		}
		if(!flag)	cout << "\n";
	}
	return 0;
}