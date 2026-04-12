#include <bits/stdc++.h>
#define INF (1LL<<60)
#define MOD7 1000000007LL
#define PREP(i, s, x) for(ll (i) = (s); (i) < (x); (i) ++)
#define MREP(i, s, x) for(ll (i) = (s); (i) >= (x); (i) --)
#define REP(i, x) PREP(i, 0, x)
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return 1;}return 0;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return 1;}return 0;}

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = INF;
    REP(i, max(x, y) + 1){
        ll sum = 2 * c * i;
        if(x - i > 0){
            sum += a * (x - i);
        }
        if(y - i > 0){
            sum += b * (y - i);
        }
        chmin(ans, sum);
    }
    cout << ans << endl;
    return 0;
}