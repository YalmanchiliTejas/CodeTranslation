#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
const int N = 1e6 + 1;

int n, a, b;
char s[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	while (true) {
		s[++n] = getchar();
		if (s[n] == '\n') {
			n--;
			break;
		}
		if (s[n] == 'A') a++;
		if (s[n] == 'B') b++;
	}
	if (a && b) cout << "Yes";
	else cout << "No";
}
