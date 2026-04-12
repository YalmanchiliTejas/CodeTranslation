#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 200010;
const int lo = 20;
const int off = 1 << lo;
const int siz = off * 2;
const long long inf = (1LL << 50);

int n, m;
int a[maxn], b[maxn], c[maxn];
long long dp[maxn];
long long tour[siz], prop[siz];
//long long niz[maxn];
vector< pair<long long, int> > niz[maxn];

void send(int node) {
     tour[node * 2] += prop[node], tour[node * 2 + 1] += prop[node];
     prop[node * 2] += prop[node], prop[node * 2 + 1] += prop[node];
     prop[node] = 0;
}

void update(int a, int b, int x, int y, int node, long long val) {
     /**
     for (int i = a; i <= b; i++)
         tour[i] += val;
     **/
     
     if (x > b || y < a) return;
     if (x >= a && y <= b) {
         tour[node] += val;
         prop[node] += val;
         //if (node >= off)
         return;
     } 
     
     send(node);
     int mid = (x + y) / 2;
     update(a, b, x, mid, node * 2, val);
     update(a, b, mid + 1, y, node * 2 + 1, val);
     tour[node] = max(tour[node * 2], tour[node * 2 + 1]);
}

long long query(int a, int b, int x, int y, int node) {
     /**
     long long sol = -inf;
     for (int i = a; i <= b; i++)
         sol = max(tour[i], sol);
     return sol;
     **/
     
     if (x > b || y < a) return -inf;
     if (x >= a && y <= b) return tour[node];
     
     send(node);
     int mid = (x + y) / 2;
     return max(query(a, b, x, mid, node * 2), query(a, b, mid + 1, y, node * 2 + 1));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", a+i, b+i, c+i);
        
    for (int i = 0; i < m; i++) {
        niz[a[i]].push_back(make_pair(c[i], a[i] - 1));
        niz[b[i] + 1].push_back(make_pair(-c[i], a[i] - 1));
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < niz[i].size(); j++)
            update(0, niz[i][j].second, 0, off - 1, 1, niz[i][j].first);
        dp[i] = query(0, i - 1, 0, off - 1, 1);
        update(i, i, 0, off - 1, 1, dp[i]);
        //for (int i = 0; i <= n; i++) printf("%d ", tour[i]); printf("\n");
    }
    //printf("debug: "); for (int i = 1; i <= n; i++) printf("%d ", dp[i]); printf("\n");
    printf("%lld\n", *max_element(dp, dp+n+1));
    //system("pause");
    return 0;   
}
