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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class question {
public:
	int N;
	ll X;
	ll lay_num(int n) {
		static ll memo[51];
		if (n == 0) return 1;
		if (memo[n]) return memo[n];
		return memo[n] = 2 * lay_num(n - 1) + 3;
	}
	ll p_num(int n, ll x) {
		if (x == 0) return 0;
		if (n == 0) return 1;
		if (x - 1 <= lay_num(n - 1)) return p_num(n - 1, x - 1);
		if (x == 2 * lay_num(n - 1) + 3) return 2 * p_num(n - 1, lay_num(n - 1)) + 1;
		return p_num(n - 1, lay_num(n - 1)) + 1 + p_num(n - 1, x - 2 - lay_num(n - 1));
	}
	vector<int> h;
	void ans() {
		cin >> N >> X;
		cout << p_num(N, X) << "\n";
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	question q;
	q.ans();

	return 0;
}