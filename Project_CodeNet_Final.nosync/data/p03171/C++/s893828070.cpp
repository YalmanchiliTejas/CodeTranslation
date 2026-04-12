#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

vector<int>a;
vector<vector<int>>dp;
int n;
int f(int l,int r){
    if(l==r)return (n%2==0?-a[l]:a[l]);
    int &ret=dp[l][r];
    if(ret!=INF)return ret;
    if((n-r+l)%2==1) ret = max(f(l+1,r)+a[l],f(l,r-1)+a[r]);
    else ret = min(f(l+1,r)-a[l],f(l,r-1)-a[r]);
    return ret;
}

signed main(){
    cin>>n;
    a.resize(n);
    dp.resize(n,vector<int>(n,INF));
    REP(i,n)cin>>a[i];
    cout<<f(0,n-1)<<endl;
}