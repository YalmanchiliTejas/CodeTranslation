#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll> > P3;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()


int n, a[5005], dp[5005][5005]; // いまi番目その前にj番目を使ったときの最長

int main() {
    cin >> n;
    REP(i,n) cin >> a[i];
    sort(a,a+n);
    REP(i,n)fill(dp[i],dp[i]+n,2);
    REP(i,n){
        REP(j,i){
            int dif = a[i]-a[j], k;
            k = lower_bound(a,a+n,a[i]+dif) -a;
            if(k < n && a[k] == a[i]+dif){
                dp[k][i] = max(dp[k][i], dp[i][j] + 1);
            }
        }
    }
    int ans = 0;
    REP(i,n)REP(j,i) ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}
