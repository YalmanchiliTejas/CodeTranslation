#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll a[n];
    rep(i,n){
        cin >> a[i];
    }
    auto isOK = [&](ll m){
        for(ll i = max(0LL, m - n); i <= m; i++){
            ll t[n];
            rep(j,n){
                t[j] = a[j] + i;
            }
            ll cnt = 0;
            rep(j,n){
                cnt += (t[j] - (n - 1) + n) / (n + 1);
            }
            if(cnt <= i) return true;
        }
        return false;
    };
    ll ng = -1, ok = LINF;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(isOK(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}