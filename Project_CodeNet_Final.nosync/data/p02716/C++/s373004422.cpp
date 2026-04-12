#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) ((a)<<(b))
#define Rshift(a,b) ((a)>>(b))
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define sz(a) int(a.size())
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;

ll in[200020];
ll dp[200020][2][2];
ll iodd[200100], ieven[200100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int i;
    rep(i, n) cin >> in[i];
    ll ans(0);
    if (n % 2 == 0) {
        ll aa(0), ab(0);
        for (i = 0; i < n; i+= 2) {
            aa += in[i];
            ab += in[i+1];
        }
        ans = max(aa, ab);
        for (i = n - 1; i >= 0; i--) {
            iodd[i] = iodd[i+1];
            ieven[i] = ieven[i+1];
            if (i % 2 == 0) {
                ieven[i] += in[i];
            } else {
                iodd[i] += in[i];
            }
        }
        ll even(0);
        for (i = 0; i < n - 3; i+=2) {
            even += in[i];
            ans = max(ans, even + iodd[i + 3]);
        }

    } else {
        memset(dp, 0xa1, sizeof(dp));
        dp[0][0][0] = in[0];
        dp[0][0][1] = 0;
        xrep(i, 1, n) {
            dp[i][0][0] = dp[i-1][0][1] + in[i];
            dp[i][0][1] = dp[i-1][0][0];
            if (i >= 2) {
                dp[i][1][0] = max(dp[i-1][1][1], dp[i-2][0][1]) + in[i];
                dp[i][1][1] = dp[i-1][1][0];
            }
        }
        ll aa(0), ab(0);
        for (i = 0; i < n - 1; i+= 2) {
            aa += in[i];
            ab += in[i+1];
        }
        ans = max(dp[n-1][1][0], dp[n-1][1][1]);
        ans = max(ans, max(dp[n-2][0][0], dp[n-2][0][1]));
        
        for (i = n - 1; i >= 0; i--) {
            iodd[i] = iodd[i+1];
            ieven[i] = ieven[i+1];
            if (i % 2 == 0) {
                ieven[i] += in[i];
            } else {
                iodd[i] += in[i];
            }
        }
        for (i = 3 ; i < n - 3; i+=2) {
            ans = max(ans, dp[i][1][0] + ieven[i + 3]);
        }
        for (i = 0; i < n - 4; i+=2) {
            ans = max(ans, dp[i][0][0] + ieven[i + 4]);
        }
    }
    cout << ans << endl;
}
