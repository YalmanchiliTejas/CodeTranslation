#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using namespace boost::multiprecision;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
using bint = cpp_int;
ll INF = 1LL<<60;

const ll M = 1000000007;
 
vector<ll> fac(3000000); //n!(mod M)
vector<ll> ifac(3000000); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0 || b < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

int main(){
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<3000000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    ll n, m, k; cin >> n >> m >> k;
    bint sum = 0;
    rep(i, 1, n){
        bint h = 1;
        h *= (ll)pow(m,2);
        h *= (n-i);
        h *= i;
        sum += h;
    }
    rep(i, 1, m){
        bint h = 1;
        h *= (ll)pow(n,2);
        h *= (m-i);
        h *= i;
        sum += h;
    }
    sum *= comb(n*m-2, k-2);
    sum %= M;
    prt(sum);
}
