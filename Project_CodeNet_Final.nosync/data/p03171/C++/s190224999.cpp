#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
const int nmax=3005;
ll a[nmax],dp[nmax][nmax];
bool mem[nmax][nmax];
int n;
ll f(int l,int r){
    if(mem[l][r]){
        return dp[l][r];
    }
    if(l==r){
        mem[l][r]=true;
        return dp[l][r]=0;
    }
    if((l+n-r)%2==0){
        mem[l][r]=true;
        return dp[l][r]=max(a[l]+f(l+1,r),a[r-1]+f(l,r-1));
    }
    else{
        mem[l][r]=true;
        return dp[l][r]=min(-a[l]+f(l+1,r),-a[r-1]+f(l,r-1));
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i,n){
        cin >> a[i];
    }
    cout << f(0,n) << endl;
}