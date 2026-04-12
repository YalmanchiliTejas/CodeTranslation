#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

void print(const std::vector<int>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    };
    
    vector<int> v(n-1);
    rep(i, n-1) v[i] = i + 1;
    int cnt = 0;
    
    do {
        // print(v);
        bool f = true;
        if (g[0][v[0]] == 0) f = false;
        
        rep(i, n-2) {
            // cout << g[v[i]][v[i+1]] << endl;
            
            if (g[v[i] ][v[i+1] ] == 0){
                f = false;
            };
        };
        if (f) cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << cnt << endl;
    return 0;
}
