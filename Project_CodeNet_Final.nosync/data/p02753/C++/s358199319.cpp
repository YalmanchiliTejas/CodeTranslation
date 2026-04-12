/* Code by pedroslrey *
 *     march 7        *
 *    Starurday       */

#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

const int INF = 1000000007;
const lli LLINF = 9223372036854775800;

#define debug(args...) fprintf(stderr, args)
#define show(x) fprintf(stderr, "[DEBUG] -> %d\n", x)

int main() {
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for (char c: s) {
		if (c == 'A') ++a;
		else ++b;
	}
	if (a && b) printf("Yes\n");
	else printf("No\n");
}