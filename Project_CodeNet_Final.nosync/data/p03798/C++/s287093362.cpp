#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int n;
string s;
vector<bool> sheep(100002), judge(100002);

bool solve(int x, int y) {
	FOR(k, 2, n) sheep[k] = (sheep[k - 1] ^ (s[k - 1] == 'o')) ? sheep[k - 2] : 1 - sheep[k - 2];
	if ((sheep[n-2] ^ (sheep[0]) ^ (sheep[n-1]) ^ (s[n-1] == 'x'))) return false;
    if ((sheep[n-1] ^ sheep[1]) ^ (sheep[0] ^ (s[0] == 'x'))) return false;
    return true;
}

int main() {
	cin >> n >> s;
	rep(i, n) judge[i] = s[i] == 'o';
	s[n] = s[0];
	rep(i, 2) rep(j, 2) {
		sheep[0] = i;
		sheep[1] = j;
		if(solve(i, j)) {
			rep(k, n) printf("%c", (sheep[k]) ? 'W' : 'S');
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
} 