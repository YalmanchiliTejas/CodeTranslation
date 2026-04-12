#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
vector<int> pathes[100050];
vector<int> children[100050];
int parent[100050];
int color[100050];
bool WIN = false;
void bfs1(int from) {
    for(int i = 0; i < pathes[from].size(); i++) {
        int to = pathes[from][i];
        if(to == parent[from]) continue;
        parent[to] = from;
        children[from].push_back(to);
        bfs1(to);
    }
}

void bfs2(int from) {
    int sum = 0;
    for(int i = 0; i < children[from].size(); i++) {
        int to = children[from][i];
        bfs2(to);
        sum += color[to];
    }
    if(sum >= 2) WIN = true;
    if(sum >= 1) color[from] = 0;
    if(sum == 0) color[from] = 1;
    if(from == 1) {
        if(sum == 0) WIN = true;
    }
}

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pathes[a].push_back(b);
        pathes[b].push_back(a);
    }
    bfs1(1);
    bfs2(1);
    if(WIN) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
