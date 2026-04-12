#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 30;

int par[MAX_N];
int rank[MAX_N];
//vector <P> G[MAX_N];

// n要素で初期化
int init_union_find (int n )
{
	rep (i, n ){
		par[i] = i;
		rank[i] = 0;
	} // end for
}

// 木の根を求める
int find (int x )
{
	if (par[x] == x )
		return x;

	// 親を遡る
	return par[x] = find (par[x] );
}

// xとyの属する集合をマージ
void unite (int x, int y )
{
	x = find (x);
	y = find (y);

	// 親が一緒なら何もしない
	if (x == y )
		return;

	// ランクが小さい方の木をぶら下げる
	if (rank[x] < rank[y] ){
		// x を y にぶら下げる
		par[x] = y;
	}else{
		// ランクが同じか rank[x] > rank[y]
		par[y] = x;
		if (rank[x] == rank[y] )
			rank[x]++;
	} // end if
}

// xとyが同じ集合に属するか否か
bool same (int x, int y )
{
	return (find (x) == find (y) );
}

int main()
{
//	cut here before submit 
//	freopen ("testcase.koukyoukoukokukikou", "r", stdin );

	const char left[] =  { 'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b' };
	const char right[] = { 'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm' };
	init_union_find (26 );
	for  (int i = 1; i < sizeof (left)/sizeof(left[0] ); i++ ){
		unite ((int)(left[0] - 'a'), (int)(left[i] - 'a') );
	} // end for
	for (int i = 1; i < sizeof (right)/sizeof (right[0] ); i++ ){
		unite ((int)(right[0] - 'a'), (int)(right[i] - 'a' ) );
	} // end for

	string str = "";
	while (cin >> str && str != "#" ){
		char curr = str[0];
		int cnt = 0;
		int n = str.length();
		for (int i = 1; i < n; i++ ){
			if (same((int)(curr - 'a'), (int)(str[i] - 'a' ) ) ) continue;
			cnt++;
			curr = str[i];
		} // end for
		printf ("%d\n", cnt );
	} // end while
		
	return 0;
}