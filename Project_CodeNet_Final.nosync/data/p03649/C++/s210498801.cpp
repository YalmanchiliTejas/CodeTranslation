#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    //全てに1を足してから最大のものをN+1引くとみなす
    ll N;
    cin >> N;
    ll a[N];
    rep(i, N) cin >> a[i];
    ll ans = 1e18;
    //最終的な操作回数をN+1で割った余りがiである場合
    rep(i, N+1){
        bool able = true;
        rep(j, N){
            if((a[j]+i)%(N+1) == N) able = false;
        }
        if(!able) continue;
        ll l = 0, r = 1e17;
        while(r-l > 1){
            ll n = (l+r)/2;
            //n*(N+1)+iを調べる
            ll x = n*(N+1)+i, sum = 0;
            rep(j, N){
                sum += (a[j]+x)/(N+1);
            }
            if(sum >= x) l = n;
            else r = n;
        }
        //cout << l << ' ' << l*(N+1)+i << endl;
        ans = min(ans, l*(N+1)+i);
    }
    cout << ans << endl;
}