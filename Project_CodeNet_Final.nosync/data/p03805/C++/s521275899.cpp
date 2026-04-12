#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> a(M,0);
    vector<ll> b(M,0);
    for(ll i=0;i<M;++i){cin>>a[i]>>b[i];a[i]--;b[i]--;}
    vector<vector<bool>> G(N, vector<bool>(N, 0));
    for(ll i=0;i<M;++i){
        G[a[i]][b[i]]=1;
        G[b[i]][a[i]]=1;
    }
    vector<ll> ord(N,0);
    iota(ord.begin(), ord.end(), 0);
    ll count=0;
    do{
        bool ok=1;
        for(ll i=1;i<N;++i){
            if(!G[ord[i-1]][ord[i]]){ok=0;break;}
        }
        if(ok)count++;
    }while(next_permutation(ord.begin()+1, ord.end()));

    prt(count)

    return 0;
}
