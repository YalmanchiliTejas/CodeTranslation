#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl '\n'
const int MAX = 8;
using namespace std;
int n;
bool table[MAX + 1][MAX + 1]; // table:無向グラフ

int dfs(int cur, bool visited[])
{
    bool all_visited = true; // すべての点を通ったかどうか
    rep(i, n)
    {
        // どこか一つでも通ったことがないならall_visitedはfalse
        if (!visited[i]) {
            all_visited = false;
        }
    }
    // すべての点に通ったならそこで終了
    if (all_visited) {
        return 1;
    }

    int cnt = 0; // cnt:すべての点を通る通り方
    rep(next, n)
    {
        if (table[cur][next] && !visited[next]) { // 今の位置curから次の位置nextに行ける ∧ nextに通ったことがない
            visited[next] = true;  // nextに行ったことにする
            cnt += dfs(next, visited); // nextに行ってすべて通ったことがあるならcnt++, ないならnextから次の点へ行く
            visited[next] = false; // curから別のnextに行けように，nextに行ったことがないとする
        }
    }
    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        table[a - 1][b - 1] = table[b - 1][a - 1] = true;
    }
    bool visited[MAX]; // visited:各点を通ったかどうか
    visited[0] = true;
    for (int i = 1; i < n; i++) {
        visited[i] = false;
    }
    cout << dfs(0, visited) << endl;
    return 0;
}