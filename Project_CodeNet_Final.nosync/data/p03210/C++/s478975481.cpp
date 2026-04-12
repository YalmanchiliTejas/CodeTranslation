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
	int X;
	void ans() {
		cin >> X;
		if (X == 3 || X == 5 || X == 7) cout << "YES\n";
		else cout << "NO\n";
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	question q;
	q.ans();

	return 0;
}

