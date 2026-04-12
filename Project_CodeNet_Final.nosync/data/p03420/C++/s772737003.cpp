#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;

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

ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }



ll solve(int N, int K) {
    // N:[1, 1e5]
    // K:[0, N)

    // a % b >= K
    // a = Pb + Q
    // Q: [0..b-1] がK以上
    // a = P*b + [K, b-1]
    // a: b進法で1の位がK以上
    // a:[1,N] b:[1,N]
    // K <= b-1,
    // K+1 <= b

    ll total = 0;
    for (int b=K+1; b<=N; ++b) {
        int w = b - K;
        int Pmax = N / b;
        // [0..Pmax)b + [K, b-1]
        int a_cnt = Pmax * w;
        if (K == 0) --a_cnt; //[0, b-1]なので
        int rem = N - Pmax*b;
        assert(IN(rem, 0, b-1));
        if (rem >= K) a_cnt += 1 + (rem - K); // (K-1);
#ifdef DEBUG
        fprintf(stderr, "b=%d: %d  ;; %dx%d, rem=%d, (+%d)\n", b, a_cnt, Pmax,w, rem, rem-K);
#endif
        total += a_cnt;
    }
    return total;
}

int main() {
    int N,K;cin>>N>>K;
    cout << solve(N,K) << endl;
    return 0;
}
