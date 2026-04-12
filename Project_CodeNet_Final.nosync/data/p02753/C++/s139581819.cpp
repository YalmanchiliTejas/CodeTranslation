#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<deque>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 29;
constexpr ll MOD = ll(1e9 + 7);
string s;

int main(void) {
	cin >> s;
	string ret = "Yes";
	if (s[0] == s[1] && s[0] == s[2] && s[1] == s[2])
		ret = "No";
	cout << ret << endl;
	return 0;
}