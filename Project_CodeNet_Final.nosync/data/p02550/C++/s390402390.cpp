//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define rep(i, n) FOR(i, 0, n)
#define rFOR(i, a, b) for(ll i = a - 1; i >= b; i--)
#define rrep(i, a) rFOR(i, a, 0)
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<char> vc;
typedef vector<vc> vvc;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ld PI = acos(-1);
const ll INF = 1e18;
struct edge{ll to, cost;};

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
      a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
      a = b;
      return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,X,M;
    cin >> N >> X >> M;
    ll Z=X;
    set<ll> st;
    vl A;
    ll kaburi0=-1,kaburi1=-1;
    rep(i,N){
        if(st.count(X)){
            rep(j,A.size()){
                if(A[j]==X){
                    kaburi0=j;
                    kaburi1=i;
                }
            }
            break;
        }
        else{
            A.pb(X);
            st.insert(X);
            X*=X;
            X%=M;
        }
    }
    if(kaburi0==-1&&kaburi1==-1){
        ll ans=0;
        rep(i,N){
            ans+=Z;
            Z*=Z;
            Z%=M;
            //cout << Z << endl;
        }
        cout << ans << endl;
        return 0;
    }
    ll ans=0;
    rep(i,kaburi0){
        ans+=A[i];
    }
    ll loop=0;
    FOR(i,kaburi0,kaburi1){
        loop+=A[i];
    }
    N-=kaburi0;
    ans+=N/(kaburi1-kaburi0)*loop;
    N%=(kaburi1-kaburi0);
    rep(i,N){
        ans+=A[kaburi0+i];
    }
    cout << ans << endl;
}
/*
overflow checked?
corner case checked?
boundary checked?
not TLE in worst case checked?
*/