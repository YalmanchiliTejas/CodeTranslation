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
int sigma(int n) {
	return n*(n + 1) / 2;
}
 
 
int main() {
	int n, k;
	cin >> n >> k;
 
	long long cnt = 0;
	FOR(b, 1, n) {
		int q = n / b;
		int r = n%b;
		cnt += q*max(0, b - k) + max(0, r - k + 1);
	}
	if (k == 0) {
		cnt -= n;
	}
 
	ANS(cnt);
 
	return 0;
}