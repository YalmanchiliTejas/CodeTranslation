#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;


int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> C(N, -1);

    ll tmp;
    for (ll i = 0; i < N; i++) {
        tmp = lower_bound(ALL(C), A[i]) - C.begin();
        C[tmp-1] = A[i];
    }
    ll ans;
    tmp = lower_bound(ALL(C), 0) - C.begin();
    ans = N - tmp;
    printf("%lld\n", ans);

}
