#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

int main()
{
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w));
    vector<ll> p(h),q(w);
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
        }
    }
    rep(i,h){
        bool ok=true;
        rep(j,w){
            if(c[i][j]=='#') ok=false;
        }
        if(ok) p[i]=1;
    }
    rep(i,w){
        bool ok=true;
        rep(j,h){
            if(c[j][i]=='#') ok=false;
        }
        if(ok) q[i]=1;
    }
    rep(i,h){
        rep(j,w){
            if(p[i]==1 || q[j]==1){
                continue;
            }
            cout << c[i][j];
        }
        if(p[i]==0) cout << endl;
    }
    return 0;
} 