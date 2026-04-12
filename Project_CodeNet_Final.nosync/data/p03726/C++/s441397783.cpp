// --------------------------------------------
// ****************  gzhffIThh  ***************
// --------------------------------------------
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int head[N], nxt[N << 1], v[N << 1], cnt, siz[N];

void add(int x, int y) {
	nxt[++cnt] = head[x]; head[x] = cnt; v[cnt] = y;
}

bool fl = 0;

void dfs(int now, int fa) {
	int su = 0;
	siz[now] = 1;
	for (int i = head[now]; i; i = nxt[i]) {
		if (v[i] == fa) continue;
		dfs(v[i], now);
		su += siz[v[i]];
		siz[now] ^= siz[v[i]];
	}
	if (su >= 2) {
		fl = 1;
	}
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;

        if (n & 1) {
                cout << "First\n";
                return 0;
        }

        for (int i = 1; i < n; i++) {
        	int x, y;
        	cin >> x >> y;
        	add(x, y);
        	add(y, x);
        }

        dfs(1, 0);

        if (fl) {
        	cout << "First\n";
        } else {
        	cout << "Second\n";
        }

        return 0; 
}