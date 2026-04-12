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
const int MAX = 210000;
const LL base = 1e9 + 7;


struct Node {
	int x, y, w;
};

LL md[11000][100];

void solve() {

	LL result = 0;
	int d;

	string k;
	cin >> k;
	cin >>d;
	md[0][0] = 1;
	for (int i = 0; i < k.size(); ++i) {
		for (int j = 0; j < d; ++j) {
			for (int t = 0; t < 10; ++t) {
				auto & x = md[i + 1][(j + t) % d];
				x += md[i][j];
				x %= base;
			}
		}
	}
	int lm = 0;
	for (int i = 0; i < k.size(); ++i) {
		for (int j = 0; '0' + j < k[i]; ++j) {
			int x = lm + j;
			x = d - x;
			x %= d;
			if (x < 0) x += d;
			result += md[k.size() - 1 - i][x];
			result %= base;
		}
		lm += k[i] - '0';
		lm %= d;
	}
	if (lm%d == 0) result++;
	result-- ;
	if (result < 0) result += base;
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
 