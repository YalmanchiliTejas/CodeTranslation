#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N, X, M;
    cin >> N >> X >> M;

    auto f = [&](ll A){
        return A*A%M;
    };

    vec<ll> cycle;
    unordered_map<ll,ll> mp;
    ll now = X;
    ll tail = X;
    ll tailcnt = 1;
    ll roop = 0;
    while(true){
        now=f(now);
        if(mp[now]==1){
            cycle.push_back(now);
            roop+=now;
            mp[now] = 2;
        } else if(mp[now] == 0){
            ++tailcnt;
            mp[now] =1;
            tail+=now;
        } else {
            break;
        }
    }

    int roopcnt = cycle.size();

    ll ans = 0;
    if(N<=tailcnt){
        ll n = X;
        ans = X;
        rep(i,N-1){
            n=f(n);
            ans+=n;
        }
    } else {
        // cout << tail << " " << tailcnt << " " << roop << " " << roopcnt << endl;
        ans = tail;
        N-=tailcnt;
        ans += (N/roopcnt)*roop;
        N=N%roopcnt;
        rep(i,N){
            ans+=cycle[i];
        }
    }
        cout << ans << '\n';

}
