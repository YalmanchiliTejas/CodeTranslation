/*
Author : N_o_o_B
Created : March 22 2020 18:30:12 
*/
#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
#define TRACE
#ifdef TRACE
#define trace(...) { cerr<<"[ "; __trace__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.first<<","<<x.second<<")";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
void __trace__(const string name, Arg1&& arg1){
    cerr << name << " : " << arg1 << " ] " << endl;
}
 
template <typename Arg1, typename... Args>
void __trace__(const string names, Arg1&& arg1, Args&&... args){
    const string name = names.substr(0,names.find(','));
    cerr<<name<<" : "<<arg1<<" | ";
    __trace__(names.substr(1+(int)name.size()), args...);
}
#else
    #define trace(args...)
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<vl> vvl;
//typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
#define fori(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define ford(i,n)  for(int i=n-1;i>=0;i--)
#define trav(x,a) for(auto& x:a)
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
#define sz(a) (int)a.size()
#define fi first
#define se second
clock_t time_p=clock();
void time_taken()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
const ll mod=998244353;
//const ll mod=1e9+7;
const ll INF=1e18;
//credits ---> ksun48


ll modinv(ll a, ll m) {
    assert(m > 0);
    if (m == 1) return 0;
    a %= m;
    if (a < 0) a += m;
    assert(a != 0);
    if (a == 1) return 1;
    return m - modinv(m, a) * m / a;
}
 
template <int MOD_> struct modnum {
private:
    int v;
public:
    static const int MOD = MOD_;
 
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int () const { return v; }
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
    modnum operator ~ () const {
        modnum res;
        res.v = modinv(v, MOD);
        return res;
    }
 
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= (~o);
    }
 
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
 
using num = modnum<mod>;
 
vector<num> fact;
vector<num> ifact;
 
void init(){
    fact = {1};
    for(int i = 1; i < 100000; i++) fact.push_back(i * fact[i-1]);
    for(num x : fact) ifact.push_back(1 / x);	
}
 
num ncr(int n, int k){
    if(k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
}
 
num powmod(num x, int a){
    if(a == 0) return 1;
    if(a & 1) return x * powmod(x, a-1);
    return powmod(x * x, a/2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout.precision(12);cout << fixed;

    int n;
    cin >> n;
    int s;
    cin >> s;
    vi a(n);
    fori(i,n) cin >> a[i];
    num ans = 0;
    vector<vector<num>> dp(n+1,vector<num>(s+1));
    vector<num> sum(s+1);
    ford(i,n){
        if(a[i]<=s) dp[i][a[i]] = (n-i);
        rep(j,a[i]+1,s){
            dp[i][j] += sum[j-a[i]];
        }
        fori(j,s+1){
            sum[j] += dp[i][j];
        }
        ans += dp[i][s]*(i+1);
    }
    cout << int(ans) << endl; 
    time_taken();
    return 0;
}