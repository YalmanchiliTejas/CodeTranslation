#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;
vector<ll> num;
vector<ll> p;

ll ans(ll n, ll x) {
    if (n==0) {
        if(x>0) return 1;
        else return 0;
    } else if (x <= num[n-1]+1) {
        return ans(n-1, x-1);
    } else {
        return p[n-1] + 1 + ans(n-1, x-2-num[n-1]);
    }
}

int main() {
    ll N, X;
    cin >> N >> X;
    num.resize(N+1);
    p.resize(N+1);
    num[0]=1;
    p[0]=1;
    rep(i, N) {
        num[i+1] = 2*num[i] + 3;
        p[i+1] = 2*p[i] + 1;
    }
    cout << ans(N, X) << endl;
    return 0;
}