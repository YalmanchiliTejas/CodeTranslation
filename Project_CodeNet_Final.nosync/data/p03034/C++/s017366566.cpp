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

signed main(){
    int n;cin>>n;
    int s[n];
    REP(i,n)cin>>s[i];
    map<pair<int,int>,int>f;
    map<int,bool>used;
    //f(k,c=a-b)の形にする
    //f(1,1....n-2)を求めよう
    //漸化式でf(k,c)を出そう
    REPS(c,n-2){
        if(n-1-c==c)continue;
        used.clear();
        f[{1,c}]=s[n-1-c]+s[c];
        used[n-1-c]=used[c]=true;
        for(int k=2;(k+1)*c<n-1;k++){
            if(n-1-k*c==k*c)break;
            if(used[n-1-k*c] or used[k*c])break;
            f[{k,c}]=f[{k-1,c}]+s[n-1-k*c]+s[k*c];
            used[n-1-k*c]=used[k*c]=true;
        }
    }
    int ans=0;
    for(auto v:f)chmax(ans,v.second);
    cout<<ans<<endl;
}