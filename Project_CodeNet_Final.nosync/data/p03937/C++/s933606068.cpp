#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <fstream>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

constexpr int INF       = 1000000000;/* 1e+9a */
constexpr int MODULO    = 1000000007;

#define REP(i,f,n) for(int i=(f); i < (n); ++i)
#define PER(i,f,n) for(int i=(n-1); i >= f; --i)


//----------------------------------
//----------------------------------

signed main()
{
    ios::sync_with_stdio(false);
	int h,w;
	int sharp = 0;
	cin >> h >> w;
	vector<vector<char>> a;
	a.push_back(vector<char>(w+2, '.'));
	h++;
	REP(i, 1, h)
	{
		a.push_back(vector<char>());
		a[i].push_back('.');
		REP(j, 0, w)
		{
			char tmp;
			cin >> tmp;
			a[i].push_back(tmp);
			sharp += tmp == '#';
		}
		a[i].push_back('.');
	}
	a.push_back(vector<char>(w+2, '.'));
	h--;

	bool possible = true;
	int nx = 1;
	int ny = 1;
	int count = 1;

	while(true)
	{
		/* cerr << nx << ';' << ny << '\n'; */
		if(nx == h && ny == w)
			break;
		else if(a[nx+1][ny] == '#')
		{
			if(a[nx][ny+1] == '#')
			{
				possible = false;
				break;
			}
			nx++;
			count++;
		}
		else if(a[nx][ny+1] == '#')
		{
			ny++;
			count++;
		}
		else
		{
			possible = false;
			break;
		}
	}
	if(count != sharp)
		possible = false;
	cout << (possible ? "Possible\n" : "Impossible\n");

}
