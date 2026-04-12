#define _GOOD_LUCK_MCLAREN_MCL32_
#define _GOOD_LUCK_FERNANDO_ALONSO_

#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
using namespace std;

const int MAX_N = (int)1e5 + 5;
struct edge {
    int u, v, w;
    edge() {}
    edge(const int &u, const int &v, const int &w) : u(u), v(v), w(w) {}
    bool operator < (const edge& e) const {
        return w < e.w;
    }
};

int xy[MAX_N][2], order[2][MAX_N], root[MAX_N];
vector<edge> g;

bool comp0(const int& i, const int& j) {
    return xy[i][0] < xy[j][0];
}

bool comp1(const int& i, const int& j) {
    return xy[i][1] < xy[j][1];
}

inline int dis(int i, int j) {
    return min(abs(xy[i][0] - xy[j][0]), abs(xy[i][1] - xy[j][1]));
}

inline int find(const int &x) {
    return (root[x] == x ? x : root[x] = find(root[x]));
}

inline bool Union(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return false;
    root[j] = i;
    return true;
}

int main() {
    int N, res = 0, cnt = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &xy[i][j]);
    
    for (int i = 0; i < N; i++) root[i] = order[0][i] = order[1][i] = i;
    sort(order[0], order[0] + N, comp0);
    sort(order[1], order[1] + N, comp1);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N - 1; j++)
            g.push_back(edge(order[i][j], order[i][j + 1],
                         dis(order[i][j], order[i][j + 1])));
    sort(g.begin(), g.end());
    
    for (vector<edge>::iterator it = g.begin(); it != g.end() && cnt < N; it++)
        if (Union(it->u, it->v)) {
            cnt++;
            res += it->w;
        }
    
    return printf("%d", res), 0;;
}
