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

// main function
int main()
{
	vector<string> ans;
	ll H = 0;
	ll W = 0;

	cin >> H >> W;
	vector<string> a;

	Rep(h, H) {
		string tmp = "";
		cin >> tmp;

		bool isAdd = false;
		Rep(i, tmp.length()) {
			if (tmp[i] != '.') {
				isAdd = true;
			}
		}
		if(isAdd) a.push_back(tmp);
	}
	H = a.size();
	W = a[0].size();

	Rep(w, W) {
		bool isAdd = false;
		string tmp = "";
		Rep(h, H) {
			if (a[h][w] != '.') {
				isAdd = true;
			}
		}
		if (isAdd) {
			Rep(h, H) tmp.push_back(a[h][w]);
			ans.push_back(tmp);
		}
	}
	H = ans.size();
	W = ans[0].size();

	Rep(w, W) {
		Rep(h, H) {
			cout << ans[h][w];
		}
		if(w != W - 1) cout << endl;
	}

	return 0;
}