#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	deque<int> b;
	REP(i, n) {
		int a;
		cin >> a;
		if (i % 2) b.push_back(a);
		else b.push_front(a);
	}
	if (n % 2 == 0) {
		REP(i, n) {
			int a = b.back();
			b.pop_back();
			cout << a;
			if (i == n - 1) cout << "\n";
			else cout << " ";
		}
	}
	else {
		REP(i, n) {
			int a = b.front();
			b.pop_front();
			cout << a;
			if (i == n - 1) cout << "\n";
			else cout << " ";
		}
	}

	return 0;
}