#include<iostream>
#include<set>
#include<vector>

using namespace std;

int ANS = 0;
int N, M;
// vector<vector<int>>* GRAPH;

void solve(int cur, set<int> traversed, vector<vector<int>>& GRAPH) {
    if (traversed.count(cur) != 0) {
        return;
    } else {
        traversed.insert(cur);
    }

    if (traversed.size() == N) {
        ANS++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (GRAPH[cur][i] == 1) {
            // is connected
            solve(i, traversed, GRAPH);
        }
    }

}

int main(void) {

    // init
    cin  >> N >> M;
    // GRAPH = new vector<vector<int>>(N, vector<int>(N, -1));
    vector<vector<int>> GRAPH(N, vector<int>(N,-1));

    // Create Graph
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        GRAPH[a-1][b-1] = 1;
        GRAPH[b-1][a-1] = 1;
    }

    // dfs
    auto traversed = set<int>();
    solve(0, traversed, GRAPH);

    cout << ANS << endl;

// 

return 0;

}