
//region Template
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "../debug_prettyprint.hpp"
#else
#define debug(...) 42
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#endif
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout<<fixed<<setprecision(12);
#define FOR(i, n) for(int i=0; i<int(n); i++)
#define RNG(i, f, t) for(int i=int(f); i<=int(t); i++)
#define REV(i, f, t) for(int i=int(f); i>=int(t); --i)
#define ALL(v) (v).begin(), (v).end()
#define EXIT(answer) { cerr<<"EXIT #"<<__LINE__<<endl; cout<<answer<<endl; exit(0); }
#define sz(v) int(v.size())
bool RELAXED = false;
template<int,typename T> struct MINMAX{ T val; MINMAX(T val) : val(val) {} };
template<typename T> MINMAX<1,T> MAX(T val) { return MINMAX<1,T>(val); };
template<typename T> MINMAX<2,T> MIN(T val) { return MINMAX<2,T>(val); };
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<1,U> rhs) { return lhs = (rhs.val > lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<2,U> rhs) { return lhs = (rhs.val < lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T, typename U> istream& operator>>(istream& in, pair<T,U> &p) { in>>p.first>>p.second; return in; }
template<typename T> inline vector<T> READ(int n) { vector<T> vec(n); FOR(i,n) cin>>vec[i]; return vec; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T> >;
typedef signed long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
//endregion

const int MOD = 1e9+7;

int main() {
    FASTIO

    int n; cin>>n;
    vi a = READ<int>(n);

    ll sum=0;
    ll ans=0;
    REV(i, n-2, 0) {
        sum += a[i+1];
        sum %= MOD;

        ans += a[i] * sum;
        ans %= MOD;
    }

    cout<<ans<<endl;

}
