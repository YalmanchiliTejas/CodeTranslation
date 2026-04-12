#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	VI A(2);
	A[0] = 1e9 + 10;
	cin >> A[1];

	FOR(i, 1, N){
		int a;
		cin >> a;

		int l = 0, r = A.size(), m;
		while(l + 1 < r){
			m = (l + r) / 2;
			if(a <= A[m]) l = m;
			else r = m;
			// cerr << a << " " << A[m] << " " << l << " " << r << endl;
		}
		m = (l + r) / 2 + 1;
		// cerr << m << endl;
		if(m < A.size()) A[m] = a;
		else A.push_back(a);
	}

	cout << A.size() - 1 << endl;

	return 0;
}
