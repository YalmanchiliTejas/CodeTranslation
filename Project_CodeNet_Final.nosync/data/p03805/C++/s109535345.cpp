#include <iostream>
using namespace std;

bool adj_matrix[8][8] = {false};
bool visit[8] = {false};
int ans = 0;
int N, M;

void DFS(int node)
{
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (adj_matrix[node][i] && !visit[i])
        {
            visit[i] = true;
            DFS(i);
            visit[i] = false;
        }
    }

    return;
}

int main()
{

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_matrix[a - 1][b - 1] = true;
        adj_matrix[b - 1][a - 1] = true;
    }

    visit[0] = true;
    DFS(0);

    cout << ans << endl;

    return 0;
}