#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> ti;
 
#define REP(a,b,c) for(ll a=(b);a<(c);a++)
#define PER(a,b,c) for(ll a=(b);a>=(c);a--)

ll ii(){ ll x; cin >> x; return x; }
string is(){ string x; cin >> x; return x; }
void oi(ll x){ cout << x; }
void od(ld x){ cout << fixed << setprecision(10) << x; }
void os(string x){ cout << x; }
void oie(ll x){ cout << x << endl; }
void ode(ld x){ cout << fixed << setprecision(10) << x << endl; }
void ose(string x){ cout << x << endl; }
void oe(){ cout << endl; }

ll f(map<ti,ll> &m, ti k, ll o){
    if(m.find(k)==m.end()){
        return LLONG_MIN;
    }
    if(m[k]==LLONG_MIN) return LLONG_MIN;
    return m[k]+o;
}

int main(){
    ll N = ii();
    vector<ll> A;
    REP(i,0,N) A.push_back(ii());

    map<ti,ll> dp;
    dp[make_tuple(0,0,0)]=0;

    REP(i,1,N+1){
        ll c=int(i/2);
        REP(j,c-1,c+2){
            dp[make_tuple(i,j,0)]=max(
             f(dp,make_tuple(i-1,j,0),0), 
             f(dp,make_tuple(i-1,j,1),0));
            dp[make_tuple(i,j,1)]=f(dp,make_tuple(i-1,j-1,0),A[i-1]);
        }
    }
    oie(max(
        dp[make_tuple(N,int(N/2),0)],
        dp[make_tuple(N,int(N/2),1)]
        ));

    return 0;
}
