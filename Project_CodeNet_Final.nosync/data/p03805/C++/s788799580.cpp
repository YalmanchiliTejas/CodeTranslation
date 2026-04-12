#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, FN) for(int i = 0; i < ( FN ); i++)

int n, m;
vector<int> v[8];
bool visited[8] = {false};

int func(int current){
    bool allvisited = true;
    FOR(i, n){
        if(visited[i] == false) allvisited = false;
    }

    if(allvisited) return 1;

    int ret = 0;
    FOR(i, v[current].size() ){
        if(visited[v[current][i]] == true) continue;

        visited[v[current][i]] = true;
        ret += func(v[current][i]);
        visited[v[current][i]] = false;
    }

    return ret;
}

int main() {
    cin >> n >> m;
    FOR(i, m){
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }

    visited[0] = true;
    cout << func(0) << endl;

    return 0;
}
