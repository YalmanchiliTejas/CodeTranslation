//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cstring>

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
	bool col[101],row[101];
	memset(col , 1 , sizeof(col));
	memset(row , 1 , sizeof(row));
	cin >> r >> c;

	for(int i=0 ; i<r ; i++)
		cin >> str[i];


	for(int i=0 ; i<r ; i++)
	{
		for(int j=0 ; j<c ; j++)
		{
			if(str[i][j] == '#')
			{
				col[j] = false;
				row[i] = false;
			}
		}
	}

	for(int i=0 ; i<r ; i++)
	{
		if(!row[i])
		{
			for(int j=0 ; j<c ; j++)
			{
				if(!col[j])
					cout << str[i][j];

			}
			cout << "\n";
		}
	}
	return 0;
}