#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct update{
    int j, k, res;
    update(int j, int k, int res) : j(j), k(k), res(res) {}
};

int main(){
    int N;
    cin >> N;
    int A[3*N+2];
    rep(i, 3*N) cin >> A[i];
    A[3*N] = A[3*N+1] = 0;

    int dp[N+1][N+1];
    rep(i, N+1) rep(j, N+1) dp[i][j] = -inf;
    dp[A[0]][A[1]] = 0;
    int M = 0, base = 0;
    int Mx[N+1], My[N+1];
    fill(Mx, Mx+N+1, -inf), fill(My, My+N+1, -inf);
    rep(i, N+1){
        rep(j, N+1){
            chmax(Mx[i], dp[i][j]), chmax(My[j], dp[i][j]);
        }
    }
    queue<update> que;

    rep(i, N){
        int b[] = {A[3*i+2], A[3*i+3], A[3*i+4]};
        if(b[0] == b[1] && b[1] == b[2]) {base++; continue;}
        rep(p, 3){
            int q = (p+1)%3, r = (q+1)%3;
            rep(j, N+1){
                que.emplace(j, b[p], max(Mx[j], My[j]));
            }
            if(b[q] == b[r]){
                int k = b[q];
                rep(j, N+1){
                    que.emplace(j, b[p], dp[j][k]+1), que.emplace(j, b[p], dp[k][j]+1);
                }
            }
            que.emplace(b[q], b[r], max(M, dp[b[p]][b[p]]+1));
        }
        while(!que.empty()){
            update e = que.front(); que.pop();
            if(chmax(dp[e.j][e.k], e.res)){
                chmax(M, e.res);
                chmax(Mx[e.j], e.res), chmax(My[e.k], e.res);
            }
        }
    }
    cout << M+base << endl;
}