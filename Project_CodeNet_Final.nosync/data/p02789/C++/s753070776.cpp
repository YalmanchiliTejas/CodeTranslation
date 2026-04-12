#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef pair<ll, ll> P;
#define ALL(v) v.begin(),v.end()

const int MOD = 1000000007;
const int MAX = 5100000;
ll gcd(ll a, ll b) {
    return (b==0) ? a : gcd(b, a%b);
}

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 以下から
const int MAX_N = 100000;
struct Edge {
    int to;
    int id;
};

const int D = 80 * 160 + 10;
const int D2 = D*2;
typedef bitset<D2> bs;
int a[100][100];
bs dp[90][90];



const int N = 20;
int h;
int w;
vector<vector<char>> maze(N, vector<char>(N,'#'));

const int MAX_WH = 21;
int d[MAX_WH][MAX_WH];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
const int INF = 100000;
int bfs(int x, int y) {
    queue<P> que;
    rep(i,MAX_WH) {
        rep(j,MAX_WH) {
            d[j][i] = INF;
        }
    }
    que.push(P(x,y));
    d[x][y] = 0;

    while (que.size()) {
        P p = que.front(); que.pop();
        for (int i=0; i< 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (0 <= nx && nx < w && 0 <= ny && ny < h && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    int mx = 0;
    rep(i,h) rep(j,w) {
            if (d[j][i] == INF) continue;
            mx = max(mx, d[j][i]);
        }
    return mx;
}

bool pairCompare(const P& firstElof, const P& secondElof)
{
    return firstElof.first < secondElof.first;
}
void dfs(){

}
const int MX = 100000;
vector<int> G[MX];
int main(){
    int n,m; cin >> n >> m;
    string ans;
    if (n == m) {
        ans = "Yes";
    } else {
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}
