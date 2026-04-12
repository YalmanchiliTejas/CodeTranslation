#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    const int m = 1000000007;
    ll ans=0;
    ll x=0;
    rep(i,n){
        ans = (ans + A[i]*x%m)%m;
        x = (x+A[i])%m;
    }
    cout << ans << endl;
    return 0;
}