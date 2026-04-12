#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()
#define INF 1e9

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
	int n;
	cin >> n;
	vi d(n);
	int jump = 0;
	bool can = true;
	rep(i, 0, n) {
		cin >> d[i];
		jump = max(jump, 10 * i + d[i]);
		if (jump < 10 * (i + 1)) can = false;
	}
	if (!can) {
		cout << "no\n";
		return 0;
	}
	jump = 0;
	reverse(all(d));
	rep(i, 0, n) {
		jump = max(jump, 10 * i + d[i]);
		if (jump < 10 * (i + 1)) {
			cout << "no\n";
			return 0;
		}
	}
	cout << "yes\n";
	return 0;
}
