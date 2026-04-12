#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Req {
    int deb, fin, add;
};

struct Node {
    int max, add, d, f;
};

const int M = 1 << 18, N = 2*M, MOD = 1e9 + 7, INF = 1e18;

Node node[N];
int n, m, val[N];
vector<Req> req[M];

int applyOp(int i, int add) {
    node[i].add += add;
    return (node[i].max += add);
}

int getMax(int i, int deb, int fin, int add) {
    if(fin <= node[i].d || node[i].f <= deb)
        return -INF;
    if(deb <= node[i].d && node[i].f <= fin)
        return applyOp(i, add);
    int j1 = i*2, j2 = j1+1;
    applyOp(j1, node[i].add);
    applyOp(j2, node[i].add);
    node[i].add = 0;
    
    int max1 = getMax(j1, deb, fin, add),
        max2 = getMax(j2, deb, fin, add);
    node[i].max = max(node[j1].max, node[j2].max);
    return max(max1, max2);
}

void afficher(int i, int prof)
{
  if (i < M) afficher(i * 2 + 1 , prof + 1);
  for (int j = 0 ; j < prof ; j++) cout << "        ";
  cout << node[i].max << ' ' << node[i].add << '\n';
  if (i < M) afficher(i * 2 , prof + 1);
}

signed main() {
    /*
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < M; i++) {
        node[i+M].d = i;
        node[i+M].f = i+1;
    }
    for(int i = M-1; i > -1; i--) {
        node[i].d = node[i*2].d;
        node[i].f = node[i*2+1].f;
    }
    for(int i = 0; i < N; i++)
        node[i].max = node[i].add = 0;
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        r++;
        req[l].push_back({l, r, a});
        req[r].push_back({l, r, -a});
    }
    
    int sum = 0;
    for(int i = 1; i <= n+1; i++) {
        for(Req j : req[i]) {
            sum += j.add;
            getMax(1, j.deb, j.fin, -j.add);
        }
        val[i] = getMax(1, 0, i, 0) + sum;
        getMax(1, i, i+1, val[i]);
    }
    int maxi = 0;
    for(int i = 0; i <= n+1; i++)
        maxi = max(maxi, val[i]);
    cout << maxi;
}