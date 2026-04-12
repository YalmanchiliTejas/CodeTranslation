#include <iostream>
#include <vector>

using namespace std;

long long N, M;
long long a[50], b[50];
long long g[8][8] = {0};

long long cnt = 0;

void solve(int now, vector<bool> is_visited) {
    for (int i = 0; i < N; i++) {
        if (!is_visited[i]) {
            break;
        } else if (i == N-1) {
            cnt++;
            return;
        }
    }
    for (int i = 0; i < N; i++) {
        if (g[now][i] == 1 && is_visited[i] == false) {
            is_visited[i] = true;
            solve(i, is_visited);
            is_visited[i] = false;
        }
    }
    return;
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < M; i++) {
        g[a[i]-1][b[i]-1] = 1;
        g[b[i]-1][a[i]-1] = 1;
    }
    vector<bool> is_v(N, false);
    is_v[0] = true;
    solve(0, is_v);
    cout << cnt << endl;
}