#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
#include <cstdlib>

using namespace std;

inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}

typedef long long ll;
#define P pair<int, int>

bool comp(const P &a, const P &b)
{
	return a.second > b.second;
}

int main()
{
	vector<P> v;
	int rank[128];
	int a, b, cnt = 0, n = 1;

	while(scanf("%d%*c%d",&a ,&b))
	{
		if(!a && !b)
		{
			break;
		}
		v.push_back( make_pair(a, b) );
		cnt++;
	}

	sort(v.begin(), v.end(), &comp);

	rank[v[0].first] = 1;
	for(int i = 1; i < cnt; i++)
	{
		if( v[i-1].second != v[i].second )
		{
			n++;
		}
		rank[v[i].first] = n;
	}

	while(cin >> a)
	{
		cout << rank[a] << endl;
	}
}