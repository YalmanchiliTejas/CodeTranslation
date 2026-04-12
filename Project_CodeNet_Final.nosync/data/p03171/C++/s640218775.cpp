#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 3005;

/* ...o(^-^)o... */
lint dp[MAX][MAX];

int main(){
    int n; cin >> n;
    vector<lint> a(n); rep(i, n) cin >> a[i];

    // dp[i][j] := 区間[i,j)から出発して、最前を尽くした時のX-Yの値
    // N-(j-i)が偶数 => max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1])
    // N-(j-i)が奇数 => min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1])

    repn(l, n){
        rep(i, n){
            int j = i+l;
            if(j>n) continue;
            if((n+j+i)%2==0) dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            else dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
        }
    }

    out(dp[0][n]);
}