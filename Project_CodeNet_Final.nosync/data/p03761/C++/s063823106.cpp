#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n;cin>>n;
    vector<vector<ll>> check(26,vector<ll>(n));
    string ans;
    rep(i,n){
        string s;
        cin>>s;

        rep(j,s.size()){
            check[(ll)(s[j]-'a')][i]++;
        }
    }

    rep(i,26){
        ll sum=INF;
        rep(j,n){
            chmin(sum,check[i][j]);
        }
        rep(j,sum){
            ans.push_back((char)('a'+i));
        }
    }

    cout<<ans<<endl;
    return 0;
}