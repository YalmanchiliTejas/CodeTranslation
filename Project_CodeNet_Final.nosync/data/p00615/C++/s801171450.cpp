#define _USE_MATH_DEFINES
#include <iostream>
#include <memory>
#include <memory.h>
#include <fstream>
#include <cmath>
#include <math.h>
#include <numeric>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <list>
#include <cctype>
#include <algorithm>
#include <complex>
using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, double> Pd;
typedef pair<int, P> PP;
typedef pair<int, PP> PPP;
const int INF = 1 << 28;
const double EPS = 1E-10;

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)

int main(){
	vector<int> nums;
	int n, m;
	int t;
	while(cin >> n >> m && (n || m)){
		nums.clear();
		nums.push_back(0);
		rep(i, n + m){
			cin >> t;
			nums.push_back(t);
		}
		sort(nums.begin(), nums.end());
		int res = 0;
		rep(i, n + m){
			res = max(res, nums[i+1] - nums[i]);
		}
		cout << res << endl;
	}
	return 0;
}