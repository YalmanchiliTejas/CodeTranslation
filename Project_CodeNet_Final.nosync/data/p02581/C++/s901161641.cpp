#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'



signed main() {
    fio();
    
    int n;
    cin >> n;
    vi a(3 * n);
    rep (i, 3 * n) {
        cin >> a[i];
        a[i]--;
    }

    vii dp(n, vi(n, -inf));
    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;

    vi temp;
    int max_score = 0;
    int off = 0;
    vi gyou_max(n, -inf);
    gyou_max[a[0]] = gyou_max[a[1]] = 0;
    rep (i, n - 1) {
        int max_score2 = max_score;

        vi temp = {a[3 * i + 2], a[3 * i + 3], a[3 * i + 4]};
        sort(all(temp));
        if (temp[0] == temp.back()) {
            off++;
            continue;
        }
        using P = pair<pii, int>;
        vector<P> up;
        for (int u: temp) {
            rep (v, n) {
                if (dp[u][v] == -inf) continue;

                rep (i, 3) {
                    if (u == v and u == temp[i]) {
                        vi uv;
                        rep (j, 3) {
                            if (i == j) continue;
                            uv.push_back(temp[j]);
                        }
                        up.emplace_back(pii(uv[0], uv[1]), dp[u][v] + 1);
                        // chmax(dp[uv[0]][uv[1]], dp[u][v] + 1);
                    }
                }

                int p = -1, q = -1;
                if (temp[0] == temp[1]) {
                    p = temp[0];
                    q = temp[2];
                }
                if (temp[1] == temp[2]) {
                    p = temp[2];
                    q = temp[0];
                }

                if (u == p) {
                    up.emplace_back(pii(q, v), dp[u][v] + 1);
                    // chmax(dp[q][v], dp[u][v] + 1);
                }
                if (v == p) {
                    up.emplace_back(pii(u, q), dp[u][v] + 1);
                    // chmax(dp[u][q], dp[u][v] + 1);
                }
            }
        }

        for (int v: temp) {
            rep (u, n) {
                if (dp[u][v] == -inf) continue;

                rep (i, 3) {
                    if (u == v and u == temp[i]) {
                        vi uv;
                        rep (j, 3) {
                            if (i == j) continue;
                            uv.push_back(temp[j]);
                        }
                        up.emplace_back(pii(uv[0], uv[1]), dp[u][v] + 1);
                        // chmax(dp[uv[0]][uv[1]], dp[u][v] + 1);
                    }
                }

                int p = -1, q = -1;
                if (temp[0] == temp[1]) {
                    p = temp[0];
                    q = temp[2];
                }
                if (temp[1] == temp[2]) {
                    p = temp[2];
                    q = temp[0];
                }

                if (u == p) {
                    up.emplace_back(pii(q, v), dp[u][v] + 1);
                    // chmax(dp[q][v], dp[u][v] + 1);
                }
                if (v == p) {
                    up.emplace_back(pii(u, q), dp[u][v] + 1);
                    // chmax(dp[u][q], dp[u][v] + 1);
                }
            }
        }

        rep (i, temp.size()) {
            for (int j = i + 1; j < temp.size(); j++) {
                up.emplace_back(pii(temp[i], temp[j]), max_score);
            }
        }

        rep (i, n) {
            rep (j, temp.size()) {
                up.emplace_back(pii(i, temp[j]), gyou_max[i]);
            }
        }

        rep (i, up.size()) {
            int u = up[i].first.first, v = up[i].first.second, c = up[i].second;
            chmax(max_score2, c);
            chmax(dp[u][v], c);
            chmax(dp[v][u], c);
            chmax(gyou_max[u], c);
            chmax(gyou_max[v], c);
        }
        swap(max_score, max_score2);
    }

    int ans = 0;
    rep (i, n) {
        rep (j, n) {
            chmax(ans, dp[i][j]);
            if (i == j and i == a.back()) {
                chmax(ans, dp[i][j] + 1);
            }
        }
    }
    cout << ans + off << endl;
}
