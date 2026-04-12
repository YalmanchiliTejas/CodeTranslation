#include <bits/stdc++.h>
#define rep(n) for (int I = 0; (I) < (n); ++(I) )
#define repeat(i, n) for( int i = 0; (i) < (n); ++(i) )
#define repeat_to(i, n) for( int i = 0; (i) <= (n); ++(i) )
#define repeat_from(i, m, n) for( int i = (m); (i) < (n); ++(i) )
#define repeat_from_to(i, m, n) for( int i = (m); (i) <= (n); ++(i) )
#define dump(x) cout << " " << #x << "=" << x
#define vdump(v) for(size_t T=0; T<v.size(); ++T){cout << " " << #v << "[" << T << "]=" << v[T];} cout << endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> edge(n, vector<bool>(n, false));
    
    rep(m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edge[a][b] = edge[b][a] = true;
    }
    
    vector<int> f(n-1);
    repeat(i, n-1) f[i] = i+1;
    
    auto check = [](const vector<int> &tf, const vector<vector<bool>> &edge) -> bool {
        vector<int> f {0};
        f.insert(f.end(), tf.begin(), tf.end());
        int n = f.size();
        
        repeat(i, n-1) {
            int src = f[i];
            int dst = f[i+1];
            if (!edge[src][dst]) return false;
        }
        return true;
    };
      
    int ans = 0;
    do {
        if (check(f, edge)) ++ans;
    } while (next_permutation(f.begin(), f.end()));
    
    cout << ans << endl;
    return 0;
}