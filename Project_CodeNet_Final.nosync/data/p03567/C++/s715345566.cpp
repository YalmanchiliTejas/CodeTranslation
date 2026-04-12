#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>
#include <cstdio>
#include <cmath>
#include <deque>

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define REP1(i,n) for(int i = 1; i <= (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define ALL(a) begin(a), end(a)
#define MP(a,b) make_pair((a), (b))
#define ROUNDUP(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))
#define X first
#define Y second
#define DEBUG(a) cout << #a << ": " << a << "\n"
// #define DEBUG(a) {}

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 1;
constexpr ll LLINF = 4 * 1e18 + 1;
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

template<typename T>
T debug(T x) {
	DEBUG(x);
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; 
	cin >> s;
	if((int)s.find("AC") != -1) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
