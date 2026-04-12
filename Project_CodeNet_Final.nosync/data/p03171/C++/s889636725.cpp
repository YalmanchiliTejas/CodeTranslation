#include <cassert>
#include <iostream>
#include <functional>
#include <iomanip>
#include <set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include  <cstring>
#include <string>
#include <cmath> 
using namespace std;
typedef long long LL;
const int MAX = 3010;
const LL base = 1e9 + 7;


struct Node {
	int x, y, w;
};

LL dp[MAX][MAX];

void solve() {

	LL result = 0;
	int n;

	cin >> n;
	vector<int> za(n);
	for (int i = 0; i < n; ++i) {
		cin >> za[i];
		dp[i][i] = za[i];
	}
	for (int gg = 1; gg < n; ++gg) {
		for (int i = 0; i < n - gg; ++i) {
			int j = i + gg;
			LL r0 = za[i] - dp[i + 1][j];
			LL r1 = za[j] - dp[i][j - 1];
			dp[i][j] = max(r0, r1);
		}
	}

	result = dp[0][n - 1];

	cout << result << endl;

}

int main() {
	const int inId = 0;
	const int outId = 0;
	if (inId>0) {
		cerr << "redirect stdin to input " << inId << endl;
		string s = "input";
		s += to_string(inId);
		s += ".txt";
		auto r = freopen(s.c_str(), "r", stdin);	
		if (r == nullptr) {
			cerr<< "invalid input file "<< s;
		}
	}
	if (outId>0) {
		cerr << "redirect stdout to stdout " << outId << endl;
		string s = "stdout";
		s += to_string(outId);
		s += ".txt";
		auto r = freopen(s.c_str(), "w", stdout);
		if (r == nullptr) {
			cerr<< "invalid output file "<< s;
		}		
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // close sync between cout and printf
	cout.precision(10);
	solve();
}
 