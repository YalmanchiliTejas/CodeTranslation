/* */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
string to_string (char s) { return string(1, s); }
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) {
	string res = "["; for (int i = 0; i < (int)v.size() - 1; i++) res += to_string(v[i]) + ", ";
	if (!v.empty()) res += to_string(v.back());	res += "]"; return res; }

const int INF = (int)1e9;

int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	vi freq(26, INF);
	int n;
	char s[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		vi t(26, 0);
		for (int j = 0; s[j]; j++) t[s[j] - 'a']++;
		for (int j = 0; j < 26; j++) freq[j] = min(freq[j], t[j]);
	}

	string res = "";
	for (int i = 0; i < 26; i++) for (int k = 0; k < freq[i]; k++) res += ('a' + i);
	printf("%s\n", res.data());
}