#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define IREP(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;

int n, m;
vector<int> adj[10];

bool connected(int i, int j) {
    int f = false;
    REP(k,adj[i].size()) {
        if (adj[i][k] == j) f = true;
    }
    return f;
}

int main() {
    cin >> n >> m;
    int a, b;
    REP(i,m) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int cnt = 0;
    vector<int> v;
    REP(i,n) {
        v.push_back(i);
    }
    
    do {
        int c = true;
        REP(i,v.size()-1) {
            if (!connected(v[i], v[i+1])) {
                c = false;
            }
        }
        if (v[0] == 0 && c) cnt++;
    } while (next_permutation(v.begin(), v.end()));
    
    cout << cnt << endl;
}
