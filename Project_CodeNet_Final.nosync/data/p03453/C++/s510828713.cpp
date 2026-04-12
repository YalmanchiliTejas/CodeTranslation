#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int mod = 1000000007;
int n, m;
long long dist[2][100000];
long long count[2][100000];
vector <pair<int, int> > v[100000];

void calc(int s, long long *dist, long long *count) {
    int i;
    priority_queue <pair<long long, int> > q;
    
    for (i = 0; i < n; i++) dist[i] = 1e18;
    
    dist[s] = 0;
    count[s] = 1;
    q.push(make_pair(0, s));
    
    while (!q.empty()) {
        int x = q.top().second;
        long long d = -q.top().first;
        
        q.pop();
        
        if (dist[x] != d) continue;
        
        for (i = 0; i < v[x].size(); i++) {
            int nx = v[x][i].first;
            long long nd = d + v[x][i].second;
            
            if (dist[nx] > nd) {
                dist[nx] = nd;
                count[nx] = count[x];
                q.push(make_pair(-nd, nx));
            } else if (dist[nx] == nd) {
                count[nx] += count[x];
                if (count[nx] >= mod) count[nx] -= mod;
            }
        }
    }
}

int main() {
    int s, t, i;
    long long sum, ans;
    vector <pair<int, pair<int, int> > > w;
    
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    
    s--;
    t--;
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
        w.push_back(make_pair(x, make_pair(y, z)));
    }
    
    calc(s, dist[0], count[0]);
    calc(t, dist[1], count[1]);
    
    sum = dist[0][t];
    ans = count[0][t] * count[1][s] % mod;
    
    for (i = 0; i < n; i++) {
        if (dist[0][i] + dist[1][i] == sum && dist[0][i] == dist[1][i]) {
            ans -= count[0][i] * count[0][i] % mod * count[1][i] % mod * count[1][i] % mod;
            if (ans < 0) ans += mod;
        }
    }
    
    for (i = 0; i < m; i++) {
        int x = w[i].first;
        int y = w[i].second.first;
        int z = w[i].second.second;
        
        if (dist[0][x] + z + dist[1][y] == sum && dist[0][x] < dist[1][x] && dist[1][y] < dist[0][y]) {
            ans -= count[0][x] * count[0][x] % mod * count[1][y] % mod * count[1][y] % mod;
            if (ans < 0) ans += mod;
        }
        
        if (dist[0][y] + z + dist[1][x] == sum && dist[0][y] < dist[1][y] && dist[1][x] < dist[0][x]) {
            ans -= count[0][y] * count[0][y] % mod * count[1][x] % mod * count[1][x] % mod;
            if (ans < 0) ans += mod;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
