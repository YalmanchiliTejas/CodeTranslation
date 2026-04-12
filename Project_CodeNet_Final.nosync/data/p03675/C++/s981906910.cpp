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
#define REVERSE(v) reverse((v).begin(),(v).end())
#define ANS(ans) cout<<(ans)<<endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)


int main() {
	int n;
	cin >> n;

	int c;
	VI odd(0);
	VI even(0);

	int now = 1;
	int reserve = 2;

	REP(i, n) {
		cin >> c;
		if (now == 1) {
			odd.push_back(c);
		}
		else {
			even.push_back(c);
		}
		swap(now, reserve);
	}

	if (n % 2 == 0) {
		REVERSE(even);
		even.insert(even.end(), odd.begin(), odd.end());
		REP(i, n - 1) {
			cout << even[i] << " ";
		}
		cout << even[n - 1] << endl;
	}
	else {
		REVERSE(odd);
		odd.insert(odd.end(), even.begin(), even.end());
		REP(i, n - 1) {
			cout << odd[i] << " ";
		}
		cout << odd[n - 1] << endl;
	}

	return 0;
}

