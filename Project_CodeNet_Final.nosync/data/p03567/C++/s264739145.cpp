#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset ((a), v, sizeof (a))

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

string S;

int main () {
	cin >> S;
	for (int i = 0; i < S.length() - 1; ++i) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			printf ("Yes\n");
			return 0;
		}
	}
	printf ("No\n");
	return 0;
}