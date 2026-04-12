//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
using namespace std;
using ll=long long;
using ld=long double;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vl A(N);
    rep(i,N){
        cin >> A[i];
    }
    multiset<ll> st;
    st.insert(A[N-1]);
    st.insert(INF);
    per(i,N-2){
        ll k=*st.upper_bound(A[i]);
        if(k==INF){
            st.insert(A[i]);
        }
        else{
            st.erase(st.find(k));
            st.insert(A[i]);
        }
    }
    cout << st.size()-1 << endl;
}