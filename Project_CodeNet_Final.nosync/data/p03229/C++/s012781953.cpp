#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    int n; cin >> n;
    vector<ll> a(n),c(n,0);
    ll ans1 = 0, ans2 = 0;

    rep(i,n) cin >> a[i];
    rep(i,n-1){
        if(i%2 == 0){
            c[i] ++;
            c[i+1] --;
        }else{
            c[i] --;
            c[i+1] ++;
        }
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());

    rep(i,n) ans1 += a[i]*c[i];

    rep(i,n) c[i] = 0;

    rep(i,n-1){
        if(i%2 == 0){
            c[i] --;
            c[i+1] ++;
        }else{
            c[i] ++;
            c[i+1] --;
        }
    }

    sort(c.begin(),c.end());

    rep(i,n) ans2 += a[i]*c[i];

    cout << max(ans1,ans2);
}
