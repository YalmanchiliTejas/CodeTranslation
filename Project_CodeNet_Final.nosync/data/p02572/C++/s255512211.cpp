#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll s = 0;
    for (ll i = 0; i < N; i++) {
        s  = (s + a[i]) % MOD;
    }

    ll ans = 0;
    ll tmp;
    for (ll i = 0; i < N; i++) {
        tmp = (MOD + s - a[i]) % MOD;
        ans = ans + tmp * a[i];
        ans = ans % MOD;
    }

    vector<ll> inv(3); inv[1] = 1;
    for (int i = 2; i < 3; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }   
    ans = ans * inv[2] % MOD;

    printf("%lld\n", ans);

}