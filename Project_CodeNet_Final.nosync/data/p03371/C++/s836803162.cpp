//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)


int main() {


	long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long ans1, ans2, ans3;

	ans1 = a*x + b*y;
	long cc = min(x, y) * 2;
	ans2 = cc * c + (x - cc/2)*a + (y - cc/2)*b;
	ans3 = 2 * max(x, y)*c;

	vector<long long> v(3);
	v[0] = ans1;
	v[1] = ans2;
	v[2] = ans3;

	SORT(v);

	ANS(v[0]);


	return 0;
}

