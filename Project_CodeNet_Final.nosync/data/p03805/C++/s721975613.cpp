#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;


int main() {
    int n,m;
    int ans = 0;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1; i<=n; i++) sort(g[i].begin(), g[i].end());
    vector<int> path(n-1);
    iota(path.begin(), path.end(), 2);

    do {
        bool f = true;
        int u = 1;
        for (int i=0; i<n-1; i++) {
            int v = path[i];
            auto it = lower_bound(g[u].begin(), g[u].end(), v);
            if (it == g[u].end() || *it != v) f = false;

            u = v;
        }
        if (f) ans++;
    } while (next_permutation(path.begin(), path.end()));

    cout << ans << endl;
}