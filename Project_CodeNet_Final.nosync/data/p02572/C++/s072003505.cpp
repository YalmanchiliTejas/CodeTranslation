#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    const ll INF = 1e9+7;
    ll N; cin >> N;
    vector<ll> A;
    vector<ll> sum;
    sum.push_back(0);
    ll ans = 0;
    rep(i,N) {
        ll a; cin >> a;
        A.push_back(a);
        ll b = (sum[i] + a);
        //b%=INF;
        sum.push_back(b);
    }

    for(ll i=0; i<N-1; i++) {
        ll x = (sum[N]-sum[i+1])%INF;
        ans += (A[i]*x)%INF;
        ans = (ans+INF)%INF;
    }
    ans = (ans + INF)%INF ;
    cout << ans << endl;
}