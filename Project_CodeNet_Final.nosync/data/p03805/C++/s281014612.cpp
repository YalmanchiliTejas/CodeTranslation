#include <iostream>
#include <vector>
#include <list>
#include <utility>


using namespace std;


vector<pair<int, int>> vertexes;
bool visited[9];
bool used[29];
int N, M;


int visit(int i, int depth)
{
    // cout << "i: " << i << ", depth: " << depth << endl;
    if (depth == N)
        return 1;

    int ans = 0;
    for (int j = 0; j < M; j++) {
        if (used[j])
            continue;

        pair<int, int> v = vertexes[j];
        if (v.first == i && !visited[v.second]) {
            visited[v.second] = used[j] = true;
            ans += visit(v.second, depth + 1);
            visited[v.second] = used[j] = false;
        } else if (!visited[v.first] && v.second == i) {
            visited[v.first] = used[j] = true;
            ans += visit(v.first, depth + 1);
            visited[v.first] = used[j] = false;
        }
    }
    return ans;
}


int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vertexes.push_back(make_pair(a, b));
    }

    for (int i = 0; i <= 9; i++)
        visited[i] = false;
    for (int i = 0; i < M; i++)
        used[i] = false;

    visited[1] = true;

    int ans = visit(1, 1);
    cout << ans << endl;

    return 0;
}
