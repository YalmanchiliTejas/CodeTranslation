#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll dp[200005][4];

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int sz = 1;
    if(n % 2) sz++;
    rep(i,n+1){
        rep(j,sz+1){
            dp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;
    rep(i,n){
        rep(j,sz+1){
            chmax(dp[i+1][j+1], dp[i][j]);
            ll next = dp[i][j];
            if((i+j) % 2 == 0) next += a[i];
            chmax(dp[i+1][j], next);
        }
    }
    cout << dp[n][sz] << endl;
}
