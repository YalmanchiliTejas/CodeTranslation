#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;
#define what(x) cerr << #x << " is " << x << endl;

int ret = 0;

void dfs(int i, vector<vector<int> > a, set<int> visited) {
    if (visited.size() == a.size()) {
        ret++;
    }
    else {
        for(auto ax : a[i]) {
            set<int> temp_v = visited;
            if(temp_v.count(ax) == 0) {
                temp_v.insert(ax);
                dfs(ax, a, temp_v);
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > a(N);
    for(int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
    set<int> visited;
    visited.insert(0);
    dfs(0, a, visited);
    cout << ret << endl;
    return 0;
}