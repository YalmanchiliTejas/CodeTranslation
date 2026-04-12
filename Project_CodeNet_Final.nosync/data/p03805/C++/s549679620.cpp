#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N,vector<int>(N,0));
    rep(i,M) {
        int a,b;cin >> a >> b;
        --a; --b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    
    vector<int> v;
    for (int i = 1;i < N;++i) v.push_back(i);
    int cnt = 0;
    do {
        if (G[0][v[0]] == 0) continue;
        bool flag = true;
        rep(i,N - 2) {
            if (G[v[i]][v[i + 1]] == 0) {
                flag = false;
            }
        }
        if (flag) ++cnt;
    } while(next_permutation(v.begin(),v.end()));
    cout << cnt << '\n';
    return 0;
}