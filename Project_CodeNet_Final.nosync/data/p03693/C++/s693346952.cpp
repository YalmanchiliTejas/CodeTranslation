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
#include <random>
#include <iterator>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define ANS(ans) cout<<(ans)<<endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;
typedef pair<int, int> P;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)


int main() {
	int r, g, b;
	cin >> r >> g >> b;

	int n = g * 10 + b;
	if (n % 4 == 0) {
		ANS("YES")
	}
	else {
		ANS("NO")
	}

	return 0;
}
