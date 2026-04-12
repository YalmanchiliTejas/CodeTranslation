#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#define rep(i, n) for(Int (i) = 0; (i) < (n); (i)++)
#define debug(var) cout << #var << ": " << var << endl
using namespace std;
using Int = int64_t;
using Uint = uint64_t;
constexpr Uint mod = 1e9 + 7;
constexpr Int Int_max = LLONG_MAX;
constexpr Int Int_min = LLONG_MIN;
using Container = vector<Int>;
using Grid = vector<vector<char>>; // [y][x]


int main() {

	Int N, M; cin >> N >> M;
	if (N == M)cout << "Yes";
	else cout << "No";

}