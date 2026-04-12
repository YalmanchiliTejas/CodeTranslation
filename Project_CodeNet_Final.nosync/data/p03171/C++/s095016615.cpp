//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
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

int N;
vl A;

ll memo[3001][3001];
ll seen[3001][3001];
ll ans(int l,int r){
    if(seen[l][r]){
        return memo[l][r];
    }
    seen[l][r]=true;
    if(l==r){
        return memo[l][r]=A[l];
    }
    return memo[l][r]=max(A[l]-ans(l+1,r),A[r]-ans(l,r-1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    A.resize(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,3001){
        rep(j,3001){
            seen[i][j]=false;
        }
    }
    cout << ans(0,N-1) << endl;
}
/*
overflow checked?
corner case checked?
boundary checked?
not TLE in worst case checked?
*/