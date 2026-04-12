#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1 << 31;
int N;
struct zahyou {
    int x, y, num;
};

bool rx( const zahyou& left, const zahyou& right ) {
    return left.x == right.x ? left.num < right.num : left.x < right.x;
}
bool ry( const zahyou& left, const zahyou& right ) {
    return left.y == right.y ? left.num < right.num : left.y < right.y;
}
vector<zahyou> vec;
struct Edge {
    int to;
    ll cost;
};
vector<Edge> c[100001];
ll mincost[100001];

typedef pair<ll, int> pii; // (cst, to)
//vector<pii> G[100001];
bool used[100001];

int prim() {
    priority_queue<pii, vector<pii>, greater<pii> > que;
    for(int i = 0; i < N; ++i){
        //mincost[i] = INF;
        used[i] = false;
    }
    que.push(pii(0,0));
    int ret = 0;
    while(!que.empty()) {
        int cst = que.top().first, v = que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v] = true;
        ret += cst;
        for(int i = 0; i < c[v].size(); i++)
            que.push(pii(c[v][i].cost, c[v][i].to));
    }
    return ret;
}
/*
int prim(){
    for(int i = 0; i < N; ++i){
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;

    while
}*/

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        vec.push_back((zahyou){x, y, i});
    }

    sort(vec.begin(), vec.end(), rx);

    zahyou px = vec[0];
    for(size_t i = 1; i < vec.size(); ++i){
        c[vec[i].num].push_back((Edge){px.num, vec[i].x - px.x});
        c[px.num].push_back((Edge){vec[i].num, vec[i].x - px.x});
        px = vec[i];
    }

    sort(vec.begin(), vec.end(), ry);

    zahyou py = vec[0];
    for(size_t i = 1; i < vec.size(); ++i){
        c[vec[i].num].push_back((Edge){py.num, vec[i].y - py.y});
        c[py.num].push_back((Edge){vec[i].num, vec[i].y - py.y});
        py = vec[i];
    }

    cout << prim() << endl;

    return 0;
}