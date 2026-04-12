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
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */

lint dp[105][5][2];

int main(){
    string n; int k; cin >> n >> k;
    int d = n.size();
    repn(i, d){
        int l = n[i-1] - '0';
        if(i == 1){
            dp[1][0][0] = 0; dp[1][0][1] = 1;
            dp[1][1][0] = 1; dp[1][1][1] = l-1;
            continue;
        }
        dp[i][0][1] = 1;
        repn(j, k){
            if(l != 0){
                dp[i][j][0] = dp[i-1][j-1][0];
                dp[i][j][1] = dp[i-1][j-1][0] * (l-1) + dp[i-1][j-1][1] * 9 + dp[i-1][j][0] + dp[i-1][j][1];
            }
            else{
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j-1][1] * 9 + dp[i-1][j][1];
            }
        }
    }
    out(dp[d][k][0] + dp[d][k][1]);
}
