#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;


bool solve()
{
	string S;
	cin >> S;
	if (S == "#")return false;

	mat cell(10, vec(10, 0));

	int num = 0;
	int x = 0, y = 0;
	int W, H = 1;
	for (int i = 0; i < S.length();++i)
	{
		if (S[i] == '/')
		{
			W = x;
			H++;
			++y;
			x = 0;
		}
		else if(S[i]  == 'b')
		{
			cell[x][y] = 1;
			++x;
		}
		else
		{
			x += (int)(S[i] - '0');
		}
	}
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	cell[--b][--a] = 0;
	cell[--d][--c] = 1;
	

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (cell[j][i])
			{
				if(num!=0)
				{
					cout << num;
					num = 0;
				}
				cout << 'b';
			}
			else
			{
				++num;
			}
		}
		if (num != 0)
		{
			cout << num;
			num = 0;
		}
		if (i == H - 1)continue;
		cout << "/";
	}
	cout << endl;
	return true;
}


int main()
{
	while(solve())
	{

	}

	return 0;
}
