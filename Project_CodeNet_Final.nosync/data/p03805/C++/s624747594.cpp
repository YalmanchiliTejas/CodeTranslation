#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;
    
    vec<vec<int>> G(N);
    rep(i, M){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    function<void(int,int,vec<bool>)> dfs = [&](int now,int count ,vec<bool> v){
        v[now] = true;
        ++count;
        if(count == N) {
            ++ans;
            return;
        }
        for(auto e:G[now]){
            if(v[e]) continue;
            dfs(e,count,v);
        }

    };

    dfs(0,0,vec<bool>(N,false));
    cout << ans << '\n';
}
