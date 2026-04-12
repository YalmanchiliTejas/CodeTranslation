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
    ll h,w;cin>>h>>w;
    vector<vector<char>> grid(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin>>grid[i][j];
        }
    }

    vector<ll> gyou(h),retu(w);
    rep(i,h){
        bool all_white=true;
        rep(j,w){
            if(grid[i][j]=='#') all_white=false;
        }
        if(all_white) gyou[i]=1;
    }
    rep(j,w){
        bool all_white=true;
        rep(i,h){
            if(grid[i][j]=='#') all_white=false;
        }
        if(all_white) retu[j]=1;
    }

    rep(i,h){
        if(gyou[i]==1) continue;
        rep(j,w){
            if(retu[j]==1) continue;

            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}