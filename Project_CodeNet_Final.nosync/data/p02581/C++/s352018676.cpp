#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,-1,-1,1,1};




int main(){
    int n;cin >> n;
    vector<int> a(3*n);
    for (int i = 0; i < 3*n; i++) {
        cin >> a[i];
        a[i]--;
    }
    LL ans = 0;
    vector<vector<int>> dp(n, vector<int> (n, -INF));
    vector<int> dp_max(n, -INF);
    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;
    dp_max[a[0]] = 0;
    dp_max[a[1]] = 0;
    int mx = 0;
    for (int i = 0; i < n - 1; i++) {
        vector<int> v{a[i * 3 + 2], a[i * 3 + 3], a[i * 3 + 4]};
        sort(ALL(v));
        auto ndp_max = dp_max;
        int p = v[0], q = v[1], r = v[2];
        auto dp0 = dp[p], dp1 = dp[q], dp2 = dp[r];
        auto f = [&](int i,int j, int k){
            chmax(dp[i][j], k);
            chmax(dp[j][i], k);
            chmax(ndp_max[i], k);
            chmax(ndp_max[j], k);
        };
        if(v[0] == v[2]) {
            ans++;
            continue;
        }
        else if(v[0] == v[1]) {
            int p = v[0], q = v[2];
            auto dpp = dp[p];
            for (int k = 0; k < n; k++) {
                f(q, k, dp0[k] + 1);
            }
        }
        else if(v[1] == v[2]) {
            int p = v[2], q = v[0];
            for (int k = 0; k < n; k++) {
                f(q, k, dp2[k] + 1);
            }
        }
        for (int k = 0; k < n; k++) {
            f(p, k, dp_max[k]);
            f(q, k, dp_max[k]);
            f(r, k, dp_max[k]);
        }

        f(p, q, max(mx, dp2[r] + 1));
        f(q, r, max(mx, dp0[p] + 1));
        f(r, p, max(mx, dp1[q] + 1));

        dp_max = ndp_max;
        for (int j = 0; j < n; j++) {
            chmax(mx, dp_max[j]);
        }
    }
    int P = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            chmax(P, dp[i][j] + (i == j and i == a[3 * n - 1]));
        }
    }
    ans += P;
    cout << ans << endl;
    return 0;
}
