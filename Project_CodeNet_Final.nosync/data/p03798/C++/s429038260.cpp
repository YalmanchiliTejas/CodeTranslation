////////////////////////////////////////////////////////////////////
// This source code is for Visual Studio
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <stack>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <deque>
#include <math.h>
#include <assert.h>

#define	numberof(a)	(sizeof(a) / sizeof(a[0]))
#define	INF32		INT32_MAX
#define	INF64		INT64_MAX
#define Rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;

typedef vector< vector<int> > MAT;
typedef pair<int, int> PINT;
typedef long long ll;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

static char get_neighbor(char before, char curr, char marubatu)
{
	char after = 0;
	if (before == 'W' && curr == 'W') {
		after = (marubatu == 'o') ? 'S' : 'W';
	}
	else if (before == 'S' && curr == 'W') {
		after = (marubatu == 'o') ? 'W' : 'S';
	}
	else if (before == 'W' && curr == 'S') {
		after = (marubatu == 'o') ? 'W' : 'S';
	}
	else if (before == 'S' && curr == 'S') {
		after = (marubatu == 'o') ? 'S' : 'W';
	}
	else {
		assert(0);
	}
	return after;
}

// main function
int main()
{
	ll N = 0;
	string s = "";
	string ans = "";

	cin >> N;
	cin >> s;

	string init_str[] = {"SS", "SW", "WS", "WW"};
	string tmp(N, '.');
	Rep(i, numberof(init_str)) {
		tmp[0] = init_str[i][0];
		tmp[1] = init_str[i][1];
		char tail = get_neighbor(init_str[i][1], init_str[i][0], s[0]);

		for (ll j = 1; j < N; ++j) {
			char next = get_neighbor(tmp[j - 1], tmp[j], s[j]);

			if (j == N - 1) {
				if (next == tmp[0] && tail == tmp[N - 1]) ans = tmp;
			}
			else {
				tmp[j + 1] = next;
			}
		}
	}

	if (ans == "") {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}