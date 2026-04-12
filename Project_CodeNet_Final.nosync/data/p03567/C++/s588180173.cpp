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

#define	numberof(a)	(sizeof(a) / sizeof(a[0]))
#define	INF		UINT64_MAX
#define Rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;

typedef vector< vector<int> > MAT;
typedef pair<int, int> PINT;
typedef long long ll;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;

int main()
{
	string S = "";
	string ret = "No";	// "Yes" or "No"
	ll status = 0;

	cin >> S;

	Rep(i, S.length()) {
		if ( S[i] == 'A') {
			status = 1;
		}
		else if (status == 1 && S[i] == 'C') {
			ret = "Yes";
			break;
		}
		else {
			status = 0;
		}
	}
	cout << ret << endl;

	return 0;
}



