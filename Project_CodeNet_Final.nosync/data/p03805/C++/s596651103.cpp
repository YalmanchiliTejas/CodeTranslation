#include <bits/stdc++.h>
#include <bitset>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>M;
    mat G(N, vec(N, 0));
    rep(i,M){
        cin>>A>>B;
        --A, --B;
        G[A][B] = G[B][A] = 1;
    }
    vec ord(N - 1);
    rep(i,N-1) ord[i] = i + 1;
    ll ans = 0;
    do{
        ll v = 0;
        bool ok = true;
        for(ll to : ord){
            ok = ok & G[v][to];
            v = to;
        }
        ans += ok;
    }while(next_permutation(ALL(ord)));
    cout<<ans<<endl;
}