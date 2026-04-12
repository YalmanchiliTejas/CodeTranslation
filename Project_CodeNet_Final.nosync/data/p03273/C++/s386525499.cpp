#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push


#define MOD 1000000007LL
#define EPS 1e-10

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> a;
	int h = 0;
	REP( i, H )
	{
		string tmp;
		cin >> tmp;
		bool isAllWhite = true;
		for( auto c : tmp )
		{
			if( c != '.' ) isAllWhite = false;
		}
		if( ! isAllWhite )
		{
			a.push_back( tmp );
			++h;
		}
	}
	H = h;

	REP( j, W )
	{
		bool isAllWhite = true;
		REP( i, H )
		{
			if( a[ i ][ j ] != '.' ) isAllWhite = false;
		}
		if( isAllWhite )
		{
			REP( i, H )
			{
				a[ i ] = a[ i ].substr( 0, j ) + a[ i ].substr( j + 1 );
			}
			--j;
			--W;
		}
	}

	REP( i, H )
	{
		cout << a[ i ] << endl;
	}
	return 0;
}
