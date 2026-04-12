#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define F first
#define S second
#define OUT(x) cout << (x) << "\n"
using namespace std;
using point = pair< int,int >;
using ll = long long;

int n;
vector< int > graph[100];
bool flag[100];

int solve(int p, int cnt);

int main() {
    int m;
    int a, b;
    cin >> n >> m;

    REP(i, m) {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    OUT(solve(1, 1));

    return 0;
}

int solve(int p, int cnt)
{
    if (flag[p]) return 0;
    if (cnt == n) return 1;

    flag[p] = true;
    int ret = 0;
    for (auto next : graph[p]) {
        ret += solve(next, cnt + 1);
    }
    flag[p] = false;

    return ret;
}
