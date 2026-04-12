#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 61;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;
typedef struct edge{
    ll to;
    ll cost;
}edge;
int main(){
    cin>>N>>M>>A>>B;
    --A; --B;
    vector<vector<edge> > G(N, vector<edge>(0));
    rep(i,M){
        cin>>L>>R>>C;
        --L; --R;
        edge e = {R,C};
        G[L].push_back(e);
        e.to = L;
        G[R].push_back(e);
    }
    vp memoA(N,P(INF,0)), memoB(N,P(INF,0)); //{Aからの距離、個数}
    priority_queue<P, vector<P>, greater<P> > pque;
    memoA[A] = mp(0,1);
    memoB[B] = mp(0,1);
    pque.emplace(0,A);
    while(!pque.empty()){
        P p = pque.top();
        ll now = p.se;
        pque.pop();
        if(p.fi > memoA[now].fi) continue;
        for(edge e : G[now]){
            if(memoA[now].fi + e.cost < memoA[e.to].fi){
                memoA[e.to].fi = memoA[now].fi + e.cost;
                memoA[e.to].se = memoA[now].se;
                pque.emplace(memoA[e.to].fi, e.to);
            }else if(memoA[now].fi + e.cost == memoA[e.to].fi){
                (memoA[e.to].se += memoA[now].se)%=MOD;
            }
        }
    }
    pque.emplace(0,B);
    while(!pque.empty()){
        P p = pque.top();
        pque.pop();
        ll now = p.se;
        if(p.fi > memoB[now].fi) continue;
        for(edge e : G[now]){
            if(memoB[now].fi + e.cost < memoB[e.to].fi){
                memoB[e.to].fi = memoB[now].fi + e.cost;
                memoB[e.to].se = memoB[now].se;
                pque.emplace(memoB[e.to].fi, e.to);
            }else if(memoB[now].fi + e.cost == memoB[e.to].fi){
                (memoB[e.to].se += memoB[now].se)%=MOD;
            }
        }
    }
    ll dist = memoA[B].fi;
    ll ans = (memoA[B].se*memoB[A].se)%MOD;
    if(dist == INF){
        cout<<0<<endl;
        return 0;
    }
    vector<bool> canU(N);
    rep(i,N) canU[i] = memoA[i].fi + memoB[i].fi == dist;
    rep(i,N){
        if(canU[i] && (memoA[i].fi * 2 <= dist)){
            if(memoA[i].fi * 2 != dist){
                for(edge e : G[i]){
                    if((memoA[e.to].fi * 2 > dist) && (memoA[i].fi + e.cost == memoA[e.to].fi) && canU[e.to]){
                        (ans += MOD - (((memoA[i].se * memoB[e.to].se) % MOD) * ((memoA[i].se * memoB[e.to].se) % MOD))%MOD) %=MOD;
                    }
                }
            }else{
                (ans += MOD - (((memoA[i].se * memoB[i].se)%MOD) * ((memoA[i].se * memoB[i].se)%MOD))%MOD)%=MOD;
            }
        }
    }
    cout<<ans<<endl;
}