#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MP make_pair
int dist[10005];
int dista[10005], distb[10005];
vector<pair<int, int> > edges[10005];
int n;
int max_val, max_ind;

void dfs(int root, int prev, int *rec) {
    for (auto ele : edges[root]) {
        if (ele.first == prev) continue;
        rec[ele.first] = rec[root] + ele.second;
        if (rec[ele.first] >= max_val) {
            max_val = rec[ele.first];
            max_ind = ele.first;
        }
        dfs(ele.first, root, rec);
    }
}

int main() {
    scanf("%d", &n);
    for (int t = 0; t < n - 1; t++) {
        int si, ti, wi;
        scanf("%d%d%d", &si, &ti, &wi);
        edges[si].push_back(MP(ti, wi));
        edges[ti].push_back(MP(si, wi));
    }
    memset(dist, 0, sizeof dist);
    memset(dista, 0, sizeof dista);
    memset(distb, 0, sizeof distb);
    max_val = 0;
    max_ind = 0;
    dfs(0, -1, dist);
    dfs(max_ind, -1, dista);
    dfs(max_ind, -1, distb);
    for (int i = 0; i < n; i++) {
        printf("%d\n", max(dista[i], distb[i]));
    }
}