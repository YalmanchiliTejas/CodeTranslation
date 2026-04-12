#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define rep(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define repd(i,n,init) for(ll i=(n);i>=init;i--)
#define repm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define repb(bit,n,init) for(ll bit=init;bit<(1<<n);++bit)

//debug の define
#define DEBUG_

// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    rep(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    rep(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

#define DUMPOUT cerr

void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

vector<ll> fact, invfact;

ll modpower(ll x, ll n, ll mod){
    ll res = 1;
    while(n){
        if(n&1)res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
ll inv(ll n){
    return modpower(n,MOD-2,MOD);
}
void COMinit(ll k){ //空っぽの配列を二つ
   k++;
   fact.resize(k, 0);
   invfact.resize(k, 0);
   fact[0] = 1;
   repi(i, k, 1)
   {
       fact[i] = fact[i - 1] * i % MOD;
   }
   invfact[k - 1] = inv(fact[k - 1]);
   repd(i, k - 2, 0)
   {
       invfact[i] = invfact[i + 1] * (i + 1) % MOD;
   }
   return;
}
ll nCk(ll n, ll k){ //この関数を使う前にCOMinit
   if (k < 0 || n < k)
       return 0LL;
   return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
ll com(ll n, ll k)
{
    ll iv = 1;
    ll fa = 1;
    repi(i, k, 0)
    {
        fa *= (n - i);
        fa %= MOD;
    }
    repi(i, k + 1, 1)
    {
        iv *= inv(i);
        iv %= MOD;
    }
    return fa * iv % MOD;
}

//---------main function----------

int main()
{
    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes"  : "No") << endl;
    return 0;
}