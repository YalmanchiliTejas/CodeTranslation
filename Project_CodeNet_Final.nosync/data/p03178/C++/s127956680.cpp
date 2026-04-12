#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a-1)
#define trav(x, a) for (auto& x: a)

const int MX  = 1e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);

int N,D;
string S;

ll dp[MX][105][2];

ll solve_dp(int p, int rem, bool can) {
    if (p == N) return (rem == 0);

    ll& res = dp[p][rem][can];
    if (res != -1) return res;

    res = 0;
    F0R(i,10) {
        if (can) { // I can put any number
            res = (res+solve_dp(p+1,(rem+i)%D,can))%MOD;
        } else { // I can put any number (i <= number) and if i == number I can't free
            int num = S[p]-'0';
            if (num >= i) res = (res+solve_dp(p+1,(rem+i)%D,num != i))%MOD;
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> S >> D;

    N = sz(S);

    F0R(i,MX) F0R(j,101) F0R(k,2) dp[i][j][k] = -1;

    cout << ((solve_dp(0,0,0)-1+MOD)%MOD) << "\n";

}
