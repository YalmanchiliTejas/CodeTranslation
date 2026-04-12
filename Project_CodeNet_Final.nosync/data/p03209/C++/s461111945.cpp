//https://atcoder.jp/contests/abc115/tasks/abc115_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,X;
#if LOCAL&01
    N=2;X=10;
#else
    cin>>N>>X;    
#endif
    vector<ll> ttl(N+1,0), ptn(N+1,0);
    ttl.at(0)=1;
    ptn.at(0)=1;
    FOR(i,1,N+1){
        ttl.at(i) = ttl.at(i-1)*2+3;
        ptn.at(i) = ptn.at(i-1)*2+1;
    }

    function<ll(ll,ll)> calc = [&](ll lv,ll x)->ll {
        ll nelv = lv-1;
        if(lv==0&&x==1) { return 1; } ;
        if(x<=1) return 0;
        else if(x<=1+ttl.at(nelv)) return calc(nelv,x-1);
        else if(x<=2+ttl.at(nelv)*2) return calc(nelv,x-ttl.at(nelv)-2)+ptn.at(nelv)+1LL;
        else return ptn.at(nelv)*2+1LL;
        assert(0);
        return 0;
    };
    ll ans = calc(N,X);
    cout<<ans<<endl;
    return 0;
}