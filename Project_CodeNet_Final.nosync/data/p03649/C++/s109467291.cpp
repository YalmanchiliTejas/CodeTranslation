#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define rt return
using dbl = double;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    vll a(N);
    ll S = 0;
    rep(i, N) {
        cin >> a[i];
        S += a[i];
    }

    for (ll x = max(0ll, S - N*(N - 1)); x <= S; ++x) {
        ll y = 0;
        rep(i, N) {
            y += (a[i] + x + 1) / (N + 1);
            if (y > x)break;
        }
        if (y == x) {
            cout << x << endl;
            break;
        }
    }
}
