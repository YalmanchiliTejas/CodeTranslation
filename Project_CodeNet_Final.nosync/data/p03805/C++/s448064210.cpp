#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int adj[10][10];
int n, m;
int ans = 0;

void bfs(bitset<8> bs, int pos) {
    int f = 1;
    imfor(i, n) {
        if (bs[i] == 0) {
            f = 0;
        }
    }
    if (f == 1) {
        ans++;
        return;
    }

    imfor(i, n) {
        if (adj[pos][i] == 1 && bs[i] == 0) {
            bs.set(i);
            bfs(bs, i);
            bs.reset(i);
        }
    }
}

int main() {
    cin >> n >> m;
    imfor(i, n) {
        imfor(j, n) {
            adj[i][j] = 0;
        }
    }
    imfor(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    bitset<8> b(1);
    bfs(b, 0);
    cout << ans << endl;
}