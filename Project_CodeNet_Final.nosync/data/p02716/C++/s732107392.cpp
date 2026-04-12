#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
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
const int MAX = 200005;

/* ...o(^-^)o... */

lint dp[MAX];
lint dq[MAX][3];

int main(){
    int n; cin >> n;
    vector<lint> a(n);
    rep(i, n) cin >> a[i];

    lint ans;
    if(n % 2 == 0){
        dp[0] = a[0]; dp[1] = a[1];
        for(int i = 2; i < n; i++){
            if(i % 2 == 1) dp[i] = max(dp[i-2]+a[i], dp[i-3]+a[i]);
            else dp[i] = dp[i-2]+a[i];
        }
        ans = max(dp[n-1], dp[n-2]);
    }
    else{
        if(n == 3){
            out(max(a[0], max(a[1], a[2]))); return 0;
        }
        dq[0][0] = a[0]; dq[1][1] = a[1];
        dq[2][2] = a[2]; dq[2][0] = a[0] + a[2];
        for(int i = 3; i < n; i++){
            dq[i][0] = dq[i-2][0] + a[i];
            dq[i][1] = max(dq[i-2][1], dq[i-3][0]) + a[i];
            dq[i][2] = max(dq[i-2][2], dq[i-3][1]) + a[i];
            if(i > 3) dq[i][2] = max(dq[i][2], dq[i-4][0] + a[i]);
        }
        ans = max(dq[n-1][2], max(dq[n-2][1], dq[n-3][0]));
    }

    out(ans);
}