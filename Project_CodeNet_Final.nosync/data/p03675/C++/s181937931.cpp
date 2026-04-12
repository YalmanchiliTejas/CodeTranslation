#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N; cin >> N;
    vector<ll> a(N+1);
    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    if(N%2 == 1){
        for (ll i = N; i > 0; i -= 2) {
            printf("%lld ", a[i]);
        }
        for (ll i = 2; i < N; i += 2) {
            printf("%lld ", a[i]);
        }
    }
    else{
        for (ll i = N; i > 0; i -= 2) {
            printf("%lld ", a[i]);
        }
        for (ll i = 1; i < N; i += 2) {
            printf("%lld ", a[i]);
        }
    }

}
