#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rfor(i, a, b) for(int i = a; i < (int)b; i++)
#define all(ary) (ary).begin(), (ary).end()
#define debug(x) cerr << #x << ": " << x << '\n'
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
using namespace std;
using v = vector<int>;
using ll = long long;
template <class T = int> T in(){ T x; cin >> x; return (x);}
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int n, m;
int res = 0;
int G[8][8];

void rec(int a, vector<int> flag){
    flag[a] = 1;
    if(accumulate(all(flag), 0) == n) res++;
    rep(i, n){
        if(G[a][i] == 0 or flag[i] or a == i) continue;
        rec(i, flag);
    }
}

int main(int argc, char *argv[]){
    cin >> n >> m;
    rep(i, 8) rep(j, 8) G[i][j] = 0;
    int a, b;
    rep(i, m){
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = 1;
    }
    v flag(n);
    rec(0, flag);
    cout << res << endl;
    return 0;
}