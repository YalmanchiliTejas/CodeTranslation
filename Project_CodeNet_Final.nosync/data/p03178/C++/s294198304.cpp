#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define WHATIS(x) cout << #x << " is " << x << endl;
#define ERROR(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x

using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

const ll MODBASE = 1000000007LL;
const int MAXN = 10010;
const int MAXM = 1000010;
const int MAXK = 110;
const int MAXQ = 200010;

string s;
int k, n;
ll dp[MAXN][MAXK][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s >> k;
    n = SZ(s);
    s = " " + s;
    dp[0][0][1] = 1;
    FOR(i,0,n-1) {
        FOR(j,0,k-1) {
            FOR(l,0,1) 
                FOR(p,0,9) {
                    if (l) {
                        if (p > s[i+1] - '0') continue;
                        if (p < s[i+1] - '0') dp[i+1][(j+p) % k][1-l] = (dp[i+1][(j+p) % k][1-l] + dp[i][j][l]) % MODBASE;
                        else dp[i+1][(j+p) % k][l] = (dp[i+1][(j+p) % k][l] + dp[i][j][l]) % MODBASE;
                    }
                    else {
                        dp[i+1][(j+p) % k][l] = (dp[i+1][(j+p) % k][l] + dp[i][j][l]) % MODBASE;
                    }
                }
        }
    }
    cout << (dp[n][0][1] + dp[n][0][0] - 1 + MODBASE) % MODBASE;
    return 0;
}
