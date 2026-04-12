//https://atcoder.jp/contests/abc095/tasks/arc096_a
//C - Half and Half
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-3.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;    
    ll ans=INT64_MAX;
    FOR(c,0,max(2*X+1,2*Y+1)){
        ll a=max(X-c/2,0LL);
        ll b=max(Y-c/2,0LL);
        ll val=a*A+b*B+c*C;
        ans = min(val,ans);
    }
    cout<<ans<<endl;
    return 0;
}