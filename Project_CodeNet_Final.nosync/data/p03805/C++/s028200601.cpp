#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> A;

bool check(vector<int> V, int i, vector<vector<int>> Graph) {
    if(i == V.size()-1) return true;
    int now = V[i];
    int nxt = V[i+1];
    int cnt  = 0;

    for(auto g : Graph[now]) {
        if(nxt != g) ++cnt;
    } 
    if(cnt == Graph[now].size()) return false;
    if(check(V, i+1, Graph)) return true;
    else return false;
}


int main() {
    int ans = 0;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Graph(N+1);

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    vector<int> V;

    for(int i = 1; i <=N; ++i) {
        V.push_back(i);
    }

    do {
        if(V[0] != 1) continue;
        bool ok = check(V, 0, Graph);
        if(ok) ++ans;
    } while(next_permutation(V.begin(), V.end()));

    cout << ans << endl;
}