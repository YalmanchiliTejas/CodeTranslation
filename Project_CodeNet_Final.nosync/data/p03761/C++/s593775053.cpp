#include <bits/stdc++.h>

using namespace std;

/*  テンプレここから */
typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, start, end) for(int i = start; i < end; ++i)
#define all(x) (x).begin(), (x).end()
#define INF (1e9)
#define INFL (1e18)
#define add_mod(a, b, x) ( (ll)(a) + (ll)(b) ) % (ll)(x)
#define mul_mod(a, b, x) ( ((ll)(a) % (ll)(x)) * ((ll)(b) % (ll)(x)) ) % (ll)(x)
#define out(x) cout << (x) << endl;
#define outyes(bool_val) cout << (bool_val ? "yes" : "no") << endl;
#define outYes(bool_val) cout << (bool_val ? "Yes" : "No") << endl;
#define outYES(bool_val) cout << (bool_val ? "YES" : "NO") << endl;
#define outPossible(bool_val) cout << (bool_val ? "Possible" : "Impossible") << endl;
#define outPOSSIBLE(bool_val) cout << (bool_val ? "POSSIBLE" : "IMPOSSIBLE") << endl;

ll sub_mod(ll a, ll b, ll x){
    ll tmp = (a - b) % x;
    if(tmp < 0) tmp += x;
    return tmp;
}
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
/*  テンプレここまで */

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int min_cnt[30];
    rep(i, 30) min_cnt[i] = 100000000;

    rep(i, n){
        int cnt[30] = {0};
        string s;
        cin >> s;
        rep(j, s.size()) ++ cnt[s[j] - 'a'];
        rep(j, 30) min_cnt[j] = min(min_cnt[j], cnt[j]);
    }

    rep(i, 30){
        rep(j, min_cnt[i]) cout << (char)('a' + i);
    }
    cout << endl;
}