#include <bits/stdc++.h>
using namespace std;

int N, M;
bool flag[10] = {};
bool edge[10][10] = {};

int dfs(int v);

int main()
{
    int ans = 0;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        edge[A][B] = true;
        edge[B][A] = true;
    }
    flag[1] = true;
    cout << dfs(1) << endl;

    return (0);
}

int dfs(int v)
{
    int ans = 0;
    int f = 1;

    for(int i = 1; i <= N; i++) {
        if(!flag[i]) {
            f = 0;
            if(edge[v][i]) {
                flag[i] = true;
                ans += dfs(i);
                flag[i] = false;
            }
        }
    }

    return (ans + f);
}
