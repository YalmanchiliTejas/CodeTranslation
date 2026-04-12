#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int num, ac, query;
char comma;
map<int, vector<int> > m;
map<int, int> rank;

int main()
{
	while (cin>>num>>comma>>ac, num|ac)
	{
		//printf("num = %d, ac = %d\n", num, ac);
		m[ac].pb(num);
	}

	int r = 1;
	for (int i=30; i>=0; i--)
	{
		if (m[i].size() > 0)
		{
			for (int j=0; j<m[i].size(); j++)
			{
				rank[m[i][j]] = r;
			}
			r++;
		}
	}

	while (cin >> query)
	{
		cout << rank[query] << endl;
	}
	
	return 0;
}