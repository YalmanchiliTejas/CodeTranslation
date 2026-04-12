#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 8;
vector<vector<int> > Graph(MAX_N + 1);
int N;
int ans;

void dfs(vector<bool> searched, int target, int depth) {
    searched[target] = true;
    if (depth == N) {
        ans++;
        return;
    } else {
        for (int to:Graph[target]) {
            if (!searched[to]) {
                dfs(searched, to, depth + 1);
            }
        }
    }
}

int main() {
    int M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    vector<bool> s(M + 1, false);
    ans = 0;
    
    dfs(s, 1, 1);
    cout << ans << endl;
}