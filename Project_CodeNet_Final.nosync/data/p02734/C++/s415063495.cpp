#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 3000+7;
const ll INF = 1e9;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 998244353;
ll A[DIM],cnt[DIM],res = 0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,S;
    cin>>n>>S;
    forn(i,n)cin>>A[i];

    forn(i,n){

        cnt[0]++;
        if (A[i]>S)continue;
        res = (res+cnt[S-A[i]]*(n-i+1))%MOD;
        for(ll v = S-A[i];v>=1;--v){
            cnt[v+A[i]]=(cnt[v+A[i]]+cnt[v])%MOD;
        }
        cnt[A[i]]=(cnt[A[i]]+i)%MOD;

        //cout<<res<<' ';
    }
    cout<<res<<endl;
    return 0;
}

