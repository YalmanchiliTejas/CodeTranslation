#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 998244353
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<ll>> dp(N, vector<ll>(S + 1, 0));
    vector<ll> sum(S + 1, 0);
    sum[0] = 1;
    rep(i, N) {
        dp[i] = sum;
        rep(j, S + 1){
            if(j - A[i] >= 0) {
                ll add = sum[j - A[i]];
                if(j - A[i] == 0) (add *= i + 1) %= mod;
                if(j == S) (add *= N - i) %= mod;
                (dp[i][j] += add) %= mod;
            }
        }
        rep(j, S + 1) {
            sum[j] = dp[i][j];
        }
    }
    output(sum[S]);

    
    return 0;
}
