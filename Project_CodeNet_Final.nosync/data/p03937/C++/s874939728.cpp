// Why I am so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

char s[105][105];

bool u[105][105];

int n, m;

void solve() {                   
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}

	int x = 1, y = 1;

	while (x != n || y != m) {
		u[x][y] = 1;

		if (x == n) {
			++y;
			continue;
		}

		if (y == m) {
			++x;
			continue;
		}

		if (s[x + 1][y] == '#') {
			++x;
		}
		else {
			++y;
		}
	}

	u[n][m] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == '#' && u[i][j] == 0) {
				printf("Impossible\n");
				return;
			}

			if (s[i][j] == '.' && u[i][j] == 1) {
				printf("Impossible\n");
				return;
			}
		}
	}
    
    printf("Possible\n");
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}