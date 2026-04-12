#include<bits/stdc++.h>
using namespace std;
#define INF 1e15
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef long long ll;
typedef pair<int, int> P;
#define END system("PAUSE");return 0
int n, m;
char c[11][11];
signed main() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> c[i][j];
		}
	}
	if (c[0][0] == '.') {
		puts("Impossible");
		END;
	}
	int x = 0, y = 0;
	c[x][y] = '.';
	while (x < n&&y < m) {
		if (c[x + 1][y] == '#') {
			x++;
			c[x][y] = '.';
		}
		else if (c[x][y + 1] == '#') {
			y++;
			c[x][y] = '.';
		}
		else if (x == n - 1 && y == m - 1)break;
		else{
			puts("Impossible");
			END;
		}
	}
	rep(i, n) {
		rep(j, m) {
			if (c[i][j] == '#') {
				puts("Impossible");
				END;
			}
		}
	}
	puts("Possible");
	END;
}
