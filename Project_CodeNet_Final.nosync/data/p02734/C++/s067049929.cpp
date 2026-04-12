#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */

lint dp[3005][3005], dp2[3005][3005];

int main(){
    lint n, s; cin >> n >> s;
    rep(i, n){
        dp[i][0] = (i+1)*(i+2)/2 - i - 1;
        dp2[i][0] = i + 2;

        dp[i][0] %= MOD9;
    }

    rep(i, n){
        lint a; cin >> a;
        if(i == 0){
            dp[0][a] = 1; dp2[0][a] = 1;
        }
        else{
            repn(w, s){
                dp[i][w] = dp[i-1][w] + dp2[i-1][w];
                dp2[i][w] = dp2[i-1][w];
                if(w >= a) dp2[i][w] += dp2[i-1][w-a];

                dp[i][w] %= MOD9; dp2[i][w] %= MOD9;
            }
        }
    }

    out((dp[n-1][s] + dp2[n-1][s]) % MOD9);
}