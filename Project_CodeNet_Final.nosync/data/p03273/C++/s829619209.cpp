#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repe(i,n) for (int i = 0; i <= (n); ++i)
#define repe1(i,n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
const int INF = 1e9;
const ll mod = 1000000007;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}

ll pow_kai(ll a, ll n) {
    ll x = 1;
    while(n > 0) {
        if(n&1) {
            x = x*a;
        }
        a = a*a;
        n >>= 1;
    }
    return x;
}

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> A(h,vector<char>(w));
    rep(i,h) {
        rep(j,w) {
            cin >> A[i][j];
        }
    }
    vector<vector<bool>> AA(h,vector<bool>(w, false));
    int hh = h;
    int ww = w;
    // 行
    rep(i,h) {
        int hh = count(all(A[i]), '.');
        if (hh == w) {
            rep(j,w) {
                AA[i][j] = true;
            }
            hh--;
        }
    }
    // 列
    rep(i,w) {
        int cntw = 0;
        rep(j,h) {
            if (A[j][i] == '.') {
                cntw++;
            }
        }
        if (cntw == h) {
            rep(k,h) {
                AA[k][i] = true;
            }
            ww--;
        }
    }

    rep(i, h) {
        int hh = count(all(AA[i]), true);
        if (hh == w) continue;
        rep(j,w) {
            if (AA[i][j] == false) {
                cout << A[i][j];
            }
        }
        cout << "\n";
    }
}