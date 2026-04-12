#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long; 
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
//constexpr long long MOD = 998244353LL;
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    RandomNumberGenerator RNG;
    int N; cin >> N;
    vector<ull> S(N),T(N),U(N),V(N);
    rep(i,N) cin >> S[i];
    rep(i,N) cin >> T[i];
    rep(i,N) cin >> U[i];
    rep(i,N) cin >> V[i];

    if (N==1) {
        if (U[0]==V[0]) {
            cout << U[0] << ln;
            return 0;
        } else {
            cout << -1 << ln;
            return 0;
        }
    }

    vector<vector<vector<int>>> mat(64, vector<vector<int>>(N, vector<int>(N,-1)));
    rep(bit,64) {
        rep(r,N) {
            if (S[r]==0 and (U[r]&(1LL<<bit))) {
                rep(c,N) {
                    mat[bit][r][c] = 1;
                }
            }
            if (S[r]==1 and !(U[r]&(1LL<<bit))) {
                rep(c,N) {
                    mat[bit][r][c] = 0;
                }
            }
        }
        rep(c,N) {
            if (T[c]==0 and (V[c]&(1LL<<bit))) {
                rep(r,N) {
                    if (mat[bit][r][c] == 0) {
                        cout << -1 << ln;
                        return 0;
                    }
                    mat[bit][r][c] = 1;
                }
            }
            if (T[c]==1 and!(V[c]&(1LL<<bit))) {
                rep(r,N) {
                    if (mat[bit][r][c] == 1) {
                        cout << -1 << ln;
                        return 0;
                    }
                    mat[bit][r][c] = 0;
                }
            }
        }
        int cnt = 0;
        while (true) {
            rep(r,N) {
                rep(c,N) {
                    if (mat[bit][r][c] != 0 and mat[bit][r][c] != 1) {
                        mat[bit][r][c] = RNG(2,4);
                    }
                }
            }
            bool ok = true;
            rep(r,N) {
                if (S[r]) {
                    int val = 0;
                    rep(c,N) {
                        if (mat[bit][r][c]%2==1) val = 1;
                    }
                    if (val != ((U[r]>>bit)&1)) ok = false;
                } else {
                    int val = 1;
                    rep(c,N) {
                        if (mat[bit][r][c]%2==0) val = 0;
                    }
                    if (val != ((U[r]>>bit)&1)) ok = false;
                }
            }
            rep(c,N) {
                if (T[c]) {
                    int val = 0;
                    rep(r,N) {
                        if (mat[bit][r][c]%2==1) val = 1;
                    }
                    if (val != ((V[c]>>bit)&1)) ok = false;
                } else {
                    int val = 1;
                    rep(r,N) {
                        if (mat[bit][r][c]%2==0) val = 0;
                    }
                    if (val != ((V[c]>>bit)&1)) ok = false;
                }
            }

            if (ok) {
                rep(r,N) {
                    rep(c,N) {
                        mat[bit][r][c] %= 2;
                    }
                }
                break;
            }
        }
    }

    vector<vector<ull>> ans(N, vector<ull>(N));
    rep(i,N) {
        rep(j,N) {
            rep(bit,64) {
                if (mat[bit][i][j]) ans[i][j] += (1LL<<bit);
            }
            cout << ans[i][j] << " ";
        }
        cout << ln;
    }
}


