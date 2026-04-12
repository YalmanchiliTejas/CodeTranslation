#include<iostream>
#include<iomanip>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const long long INF = 1LL << 60;
typedef pair<int, int> P;

bool visited[8];
int N, M;
vector<int> G[8];

int dfs(int u, int count) {
    if (count == N) return 1;
    int res = 0;
    for (int i = 0; i < G[u].size(); i++) {
        if (!visited[G[u][i]]) {
            visited[G[u][i]] = true;
            res += dfs(G[u][i], count+1);
            visited[G[u][i]] = false;
        }
    }
    return res;
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1); 
        G[b-1].push_back(a-1); 
    }
    visited[0] = true;
    cout << dfs(0, 1) << "\n";
}

/*
int N, M;

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

int main() {
    cin >> N >> M;

    if (2 * N > M || 4 * N < M) {
        cout << "-1 -1 -1\n";
        return 0;
    }

    int dif = abs(3 * N - M);

    if (3 * N >= M) {
        cout << dif << " " << N - dif << " 0\n";
    } else {
        cout << "0 " << N - dif << " " << dif << "\n";
    }
}
*/
/*
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> cost(N+1, 0);
    cost[1] = abs(a[1]-a[0]);
    for (int i = 2; i < N; i++) {
        int c = abs(a[i] - a[i-1]) + cost[i-1];
        chmin(c, abs(a[i] - a[i-2]) + cost[i-2]);
        cost[i] = c;
    }
    cout << cost[N-1] << "\n";
}
*/