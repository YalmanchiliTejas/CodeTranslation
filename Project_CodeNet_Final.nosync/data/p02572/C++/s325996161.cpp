#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A.at(i);

    ll ans = 0;
    ll sum_value = 0;
    ll mod_value = 1000000007;

    rep(i,N-1){
        sum_value += A.at(i);
        sum_value %= mod_value;
        ll multi_value = sum_value*A.at(i+1);
        multi_value %= mod_value;
        ans += multi_value;
        ans %= mod_value;
    }

    cout << ans << endl;

    return 0;
}