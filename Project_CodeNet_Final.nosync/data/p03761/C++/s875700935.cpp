#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<string> S(n);
    for(ll i=0;i<n;++i)cin>>S[i];
    vector<vector<ll>> count(n, vector<ll>(26, 0));
    for(ll i=0;i<n;++i){
        for(auto c: S[i]){
            count[i][c-'a']++;
        }
    }
    for(ll i=1;i<n;++i){
        for(ll j=0;j<26;++j)chmin(count[0][j],count[i][j]);
    }
    string ans="";
    for(ll i=0;i<26;++i){
        for(ll j=0;j<count[0][i];++j){
            ans+='a'+i;
        }
    }
    prt(ans)

    return 0;
}
