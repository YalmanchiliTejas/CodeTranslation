#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x,m;cin >> n >> x >> m;
    vector<vector<int>> d(41,vector<int>(m));
    vector<vector<ll>> s(41,vector<ll>(m));
    for(ll i=0;i<m;i++){
        d[0][i]=i*i%m;
        s[0][i]=i*i%m;
    }
    REP(i,40){
        REP(j,m){
            d[i+1][j]=d[i][d[i][j]];
            s[i+1][j]=s[i][j]+s[i][d[i][j]];
        }
    }
    n--;
    ll ans=x;
    int cnt=0;
    while(n){
        if(n&1){
            ans+=s[cnt][x];
            x=d[cnt][x];
        }
        cnt++;
        n>>=1;
    }
    cout << ans << endl;
}