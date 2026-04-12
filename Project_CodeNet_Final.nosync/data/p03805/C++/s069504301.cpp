#include <bits/stdc++.h>

using namespace std;
const int N = 10;
int p[N];
bool graph[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i++) {
        p[i] = i;
        for (int j = 0; j < N; j++) {
            graph[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    int res = 0;
    do {
        bool cur_ans = true;
        for (int i = 0; i < n - 1; i++) {
            if (!graph[p[i]][p[i + 1]]) {
                cur_ans = false;
                break;
            }
        }
        if (cur_ans) res++;
    } while (next_permutation(p + 1, p + n));
    cout << res << endl;
    return 0;
}
