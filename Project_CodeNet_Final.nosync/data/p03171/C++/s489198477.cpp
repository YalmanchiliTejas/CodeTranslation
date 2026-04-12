#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

using ld = long double;
using vd = vector<double>;
using vvd = vector<vd>;

using vb = vector<bool>;
using vvb = vector<vb>;

#define FOR(i,a,b) for(ll i=(a); i < (b); (i)++)

#define DBG 0
#define TR(X) ({if (DBG) cerr << "TR " << (#X) << " = " << (X) << endl; })
#define TRM(i,j,c) ({if (DBG) cerr << "TR (" << (i) << ", " << (j) << ") = " << (c)[i][j] << endl;})

int main(void){
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    vl a(N);
    FOR(i,0,N)
        cin >> a[i];

    vvl dp(N+1, vl(N));

    FOR(i,1,N+1) FOR(j,0,N) {
        ll k = j+(i-1);
        if(k >= N)
            continue;

        if(j+1 >= N) {
            dp[i][j] = a[k] - dp[i-1][j];
        } else {
            dp[i][j] = max(a[j] - dp[i-1][j+1], a[k] - dp[i-1][j]);
        }
        TR(k);
        TRM(i,j,dp);
    }

    cout << dp[N][0] << endl;
}
