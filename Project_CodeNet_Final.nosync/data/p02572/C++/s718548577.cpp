#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> ti;
 
#define REP(a,b,c) for(ll a=b;a<(c);a++)
#define PER(a,b,c) for(ll a=b;a>=(c);a--)
 
inline ll ii(){ ll x; cin >> x; return x; }
inline string is(){ string x; cin >> x; return x; }
inline ld id(){ ld x; cin >> x; return x; }
inline void oi(ll x){ cout << x; }
inline void od(ld x){ cout << fixed << setprecision(10) << x; }
inline void os(string x){ cout << x; }
inline void oe(){ cout << endl; }
inline void oie(ll x){ oi(x); oe(); }
inline void ode(ld x){ od(x); oe(); }
inline void ose(string x){ os(x); oe(); }
inline void maxin(ll &a, ll b){ a=max(a,b); }
inline void minin(ll &a, ll b){ a=min(a,b); }


int main(){
    ll N=ii();
    ll S=0;
    ll mod=1E9+7;
    vector<ll> A;
    REP(i,0,N){
        ll a=ii();
        S+=a;
        S%=mod;
        A.push_back(a);
    }
    ll m=0;
    ll ret=0;
    REP(i,0,N-1){
        S=(S-A[i]+mod)%mod;
        ll t=A[i]*S;
        t%=mod;
        ret+=t;
        ret%=mod;
    }
    oie(ret);

    return 0;
}