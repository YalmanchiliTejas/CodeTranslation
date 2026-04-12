#define _USE_MATH_DEFINES
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
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

// 問題
// 1<=a,b<=N
// a mod b >= K
// 組(a, b)としてありうるものを数えよ
// 1<=N<=10^5
// 
// 0<=K<b, q>=0
// r >= K
// a = bq + r
// r = a-bq
// K<=r<b
// K<=a-bq<b
// K+bq<=a<b(q+1)
// よって1<=b<=Nの範囲でbを総当たりして
// 更にK+bq<=N の範囲でqを総当たり
// これは調和数を考えると実行時間が
// O(NlogN)になるやつ

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll N, K;
    cin >> N >> K;
    ll ans = 0;

    for (ll b = 1; b <= N; ++b) {
        for (ll q = 0; K + b*q <= N; ++q) {
            ll lb = max(1ll, K + b*q);
            ll ub = min(N, b*(q + 1) - 1);
            if(lb<=ub)ans += ub - lb + 1;
        }
    }
    cout << ans << endl;
}