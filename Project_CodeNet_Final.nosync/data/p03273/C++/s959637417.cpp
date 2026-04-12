//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
//#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long long int ll;

//define
#define INF 1e9 
#define NUM 1000000007
#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)



int main() {
	int h, w,hcnt,wcnt;
	cin >> h >> w;
	VI h_cnt(h),w_cnt(w);
	VS a(h);
	rep(i, h) cin >> a[i];

	rep(i, h) {
		hcnt = 0;
		rep(j, w) {
			if (a[i][j] == '.') hcnt++;
		}

		if (hcnt == w) {
			h_cnt[i]++;
		}
	}

	rep(i, w) {
		wcnt = 0;
		rep(j, h) {
			if (a[j][i] == '.') wcnt++;
		}
		if (wcnt == h) {
			w_cnt[i]++;
		}
	}

	rep(i, h) {
		if (h_cnt[i] > 0) continue;
		rep(j, w) {
			if (w_cnt[j] > 0) {
				continue;
			}
			cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}


