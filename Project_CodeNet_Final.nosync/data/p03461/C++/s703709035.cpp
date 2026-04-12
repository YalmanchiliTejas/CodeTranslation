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

struct edge{
    int u, v, c;
    edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

int main(){
    int A, B;
    cin >> A >> B;
    int d[A][B];
    rep(i, A){
        rep(j, B) cin >> d[i][j];
    }
    int N = 202, s = 1, t = 202;
    vector<edge> es;
    rep2(i, 1, 100){
        es.eb(i, i+1, -1), es.eb(202-i, 203-i, -2);
    }
    bool flag[A][B];
    memset(flag, false, sizeof flag);
    rep2(a, 0, 100){
        rep2(b, 0, 100){
            int M = -inf;
            rep(i, A){
                rep(j, B) chmax(M, d[i][j]-(a*(i+1)+b*(j+1)));
            }
            if(M >= 0){
                es.eb(a+1, 202-b, M);
                rep(i, A){
                    rep(j, B){
                        if(d[i][j]-(a*(i+1)+b*(j+1)) == M) flag[i][j] = true;
                    }
                }
            }
        }
    }
    rep(i, A){
        rep(j, B){
            if(!flag[i][j]) {cout << "Impossible" << endl; return 0;}
        }
    }
    cout << "Possible" << endl;
    cout << N << ' '<< sz(es) << endl;
    for(auto &e: es){
        cout << e.u << ' ' << e.v << ' ';
        if(e.c < 0){
            cout << (e.c == -1? "X" : "Y") << endl;
        }
        else cout << e.c << endl;
    }
    cout << s << ' ' << t << endl;
}