#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000; //
const ll LINF = (ll) 4000000000000000000; //
const ll MOD = (ll) 1000000007; //
const double PI = 3.1415926535898; //
const int limit = 100010;

#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep2(i,n) REP(i,1,n+1)
#define rep3(i,n) REP(i,0,n+1)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define repll(i,n) REPLL(i,0,n)
#define repll2(i,n) REPLL(i,1,n+1)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())

//------------------------------------------------------
int n;

inline int mod(int a) {
    return (a + n) % n;
}

int main() {
    string s;
    cin >> n >> s;

    rep(a, 2) {

        rep(b, 2) {
            bool sheep[n];
            sheep[0] = (a == 0);
            sheep[1] = (b == 0);

            REP(i, 1, n) {
                if ((s[mod(i)] == 'o') == sheep[mod(i)]) sheep[mod(i + 1)] = sheep[mod(i - 1)];
                else sheep[mod(i + 1)] = !sheep[mod(i - 1)];
            }

            bool can = true;

            rep(i, n) {
                if ((sheep[i] == (s[i] == 'o')) != (sheep[mod(i - 1)] == sheep[mod(i + 1)])) {
                    can = false;
                    break;
                }
            }

            if (can) {
                rep(i, n) cout << (sheep[i] ? 'S' : 'W');
                cout << endl;
                return 0;
            }

        }
    }

    cout << -1 << endl;

    return 0;
}