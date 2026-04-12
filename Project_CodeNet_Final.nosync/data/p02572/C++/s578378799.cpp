#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)

#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using sl = stack<ll>;
using ql = queue<ll>;

const long long INF=2305843009213693951;
const long long dx[]={0,1,0,-1,1,-1,1,-1};
const long long dy[]={1,0,-1,0,1,1,-1,-1};


void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}

int binary_search(ll x, vl a){
    auto ite = lower_bound(ALL(a), x);
    if(ite != a.end() && *ite == x) {
        return ite - a.begin() ;
    } else {
        return -1;
    }

}

ll modpow(ll a, ll n, ll mod) {
    if(n == 0)
        return 1;
    if(n == 1)
        return a % mod;
    if(n % 2 == 1)
        return (a * modpow(a, n - 1, mod)) % mod;
    ll t = modpow(a, n / 2, mod);
    return (t * t) % mod;
}

int main() {
    ll MOD = 1000000007;
    ll N, num, sum = 0, ans = 0;
    cin >> N;
    vl A(N), S(N);
    REP(i, N) {
        cin >> num;
        A[i] = num;
        sum += num;
        S[i] = sum;
    }
    REP(i, N-1){
        num = S[N-1] - S[i];
        num %= MOD;
        ans += A[i] * num;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}