//=======Includes=======||
#include <iostream>     //
#include <cmath>        //
#include <cstdio>       //
#include <cstring>      //
#include <utility>      //
#include <cstdlib>      //
#include <cassert>      //
#include <ctime>        //
#include <sstream>      //
#include <algorithm>    //
#include <functional>   //
#include <numeric>      //
#include <string>       //
#include <vector>       //
#include <queue>        //
#include <stack>        //
#include <map>          //
#include <set>          //
#include <iomanip>      //
//======================||

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define fastio() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
#define ll long long
#define ld long double

int main()
{
	fastio();
	int n, m;
	cin >> n >> m;
	vector<vector<char>> A(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	//vector<vector<int>> B;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == '.')
			{
				count++;
			}
		}
		if (count == m)
		{
			A.erase(A.begin() + i);
			i--;
			n--;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (A[j][i] == '.')
			{
				count++;
			}
		}
		
		if (count == n)
		{
			for (int j=0;j<n;j++)
			{
				A[j].erase(A[j].begin() + i);
			}
			m--;
			i--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j] << "";
		}
		cout << endl;
	}
	return 0;
}