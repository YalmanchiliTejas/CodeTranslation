// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 1000005
#define INF (ll)1e18
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define vv vector
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define repr(i,n) repr2(i,n,0)
#define repr2(i,m,n) for(ll i=m;i>=(n);i--)
#define get(n) ll (n); scanf("%lld",&(n));
#define get2(n,k) ll (n),(k); scanf("%lld%lld",&(n),&(k));
#define get3(n,m,k) ll (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k));
#define gets(s) string (s); cin >> (s);
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) vector<ll> A((n)); for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); //cout.tie(0);
#define pi 3.1415926535897
#define db double
#define noop
#define flu fflush(stdout)
#define imp {cout<<"NO\n"; return 0;}
#define debug_vec(vec,n) {rep(idxi,n) cout<<vec[idxi]<<" "; cout<<"\n";}
#define debug_pvec(vec,n) {rep(idxi,n) cout<<vec[idxi].fi<<"-"<<vec[idxi].se<<"  "; cout<<"\n";}
#define debug_set(seta) {cout<<seta.size()<<"\n"; for(auto idxi:seta) cout<<idxi<<" "; cout<<"\n";}
#define debug_map(mappa) {cout<<mappa.size()<<"\n";for(auto idxi:mappa) cout<<idxi.fi<<"-"<<idxi.se<<"  "; cout<<"\n";}

int main() {

    get2(n,m);
    if(m==n) cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;  
}