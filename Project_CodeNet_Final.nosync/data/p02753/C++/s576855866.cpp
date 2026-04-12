#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define rep(i,n) for(int64_t i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr int64_t INF=(1ll<<60);
constexpr int64_t mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string s;cin>>s;
    sort(s.begin(),s.end());
    ll n=s.size();

    bool ok=false;
    rep(i,n-1){
        if(s[i]!=s[i+1]) ok=true;
    }

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}