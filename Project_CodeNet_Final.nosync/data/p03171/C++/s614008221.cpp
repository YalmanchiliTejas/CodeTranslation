#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define loop(i,b,n) for(int i=b;i<(n);++i)
#define each(e,v) for(auto &&e : v)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)v.size()

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const double EPS = 1e-9;
const ll MOD = 1e+9 + 7;

template<typename A,typename B> inline void chmin(A &a,B b){ if(a>b) a=b; }
template<typename A,typename B> inline void chmax(A &a,B b){ if(a<b) a=b; }
template <typename T> inline void print(const T& x) { cout << x << endl; }

int main() {
    int n;
    cin >> n;

    std::vector<ll> a(n,0);
    for(int i=0; i<n; ++i) cin >> a[i];

    if(n==1){
        print(a[0]);
        return 0;
    }

    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i=0; i<n-1; ++i){
        dp[i][i+1] = abs(a[i]-a[i+1]);
    }

    for(int d=2; d<=n-1; ++d){
        for(int i=0; i<n-d; ++i){
            dp[i][i+d] = max(a[i] - dp[i+1][i+d], a[i+d] - dp[i][i+d-1]);
        }
    }

    print(dp[0][n-1]);

    return 0;
}