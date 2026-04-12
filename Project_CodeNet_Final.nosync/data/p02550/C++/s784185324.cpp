#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N; cin >> N;
    ll X, M; cin >> X >> M;
    vector<pair<int, int>> appear(M, pair<int, int>(-1, -1));
    appear[X].first = 0;
    bool become_zero = false;
    ll now = X;
    ll ans = 0;
    ll reappear_num = -1;
    rep(i, M){
        now = (now * now) % M;
        if(now == 0){
            become_zero = true;
            break;
        }
        else if(appear[now].first != -1){
            reappear_num = now;
            appear[now].second = i+1;
            break;
        }
        else appear[now].first = i+1;
    }
    if(become_zero){
        now = X;
        rep(i, N){
            if(now == 0) break;
            ans += now;
            now = (now * now) % M;
        }
    }
    else{
        ll orbit_len = appear[reappear_num].second - appear[reappear_num].first;
        ll beg = appear[reappear_num].first;
        ll whole = ((N-beg) - ((N-beg) % orbit_len)) / orbit_len, las = N - beg - whole*orbit_len;
        ll now = reappear_num;
        rep(i, orbit_len) {ans += now; now = (now*now) % M;}
        
        //cout << whole << " " << beg << " " << las << endl;

        ans *= whole;
        now = X;
        rep(i, beg){
            ans += now;
            now = (now * now) % M;
        }
        now = reappear_num;
        rep(i, las){
            ans += now;
            now = (now * now) % M;
        }
    }
    cout << ans << endl;
    return 0;
}