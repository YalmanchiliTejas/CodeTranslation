#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N;
int A[110000], B[110000];
int deg[110000];
bool used[110000];
vint G[110000];
signed main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        deg[A[i]]++, deg[B[i]]++;
        G[A[i]].push_back(B[i]), G[B[i]].push_back(A[i]);
    }
    queue<int> one;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 1)one.push(i);
    }
    while (!one.empty()) {
        int x = one.front(); one.pop();
        if (used[x])continue;
        used[x] = true;
        int y = -1;
        for (int i = 0; i < G[x].size(); i++) {
            if (used[G[x][i]])continue;
            deg[G[x][i]]--, y = G[x][i];
            if (deg[G[x][i]] == 1)one.push(G[x][i]);
        }
        if (y == -1) {
            cout << "First" << endl;
            return 0;
        }
        used[y] = true;
        for (int i = 0; i < G[y].size(); i++) {
            if (used[G[y][i]])continue;
            deg[G[y][i]]--;
            if (deg[G[y][i]] == 1)one.push(G[y][i]);
        }

    }
    cout << "Second" << endl;

}
