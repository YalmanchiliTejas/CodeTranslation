#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


pair<ll, ll> min_max(vector<ll>& a) {
    ll amin = LLONG_MAX, amax = LLONG_MIN;
    for (int i=a.size()-1; i>=0; --i) {
        amin = min(amin, a[i]);
        amax = max(amax, a[i]);
    }
    return make_pair(amin, amax);
}

ll solve(ll N, vector<ll>& a) {
    auto amm = min_max(a);
    ll amin = amm.first, amax = amm.second;
    if (amax <= N-1) return 0;

    ll s = 0;
    if (amax - amin >= N+1) {
        rep(i, N) {
            s += a[i] / (N+1);
            a[i] %= (N+1);
        }
        rep(i, N) {
            a[i] += s;
        }
    }
    // amax - amin < N+1
    amm = min_max(a);
    amin = amm.first; amax = amm.second;
    if (amin > N*2) {
        ll d = amin - N*2;
        rep(i, N) a[i] -= d;
        s += N * d;
    }
    // amin <= 2N
    priority_queue<ll> pq;
    rep(i, N) pq.push(a[i]);
    ll ofs = 0;
    while (true) {
        ll t = pq.top(); pq.pop();
        if (ofs + t <= N-1) break;
        pq.push(t - (N+1));
        ++ofs;
        ++s;
    }

    return s;
}

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    cout << solve(N,a) << endl;
    return 0;
}
