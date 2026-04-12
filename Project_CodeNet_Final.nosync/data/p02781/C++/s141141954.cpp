#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
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
int main(){
    string s;cin >> s;
    ll k;cin >> k;
    ll sz=s.size();
    vvl dp1(sz+1,vl(k+1,0));
    vvl dp0(sz+1,vl(k+1,0));
    dp1[0][0]=1;
    rep(i,sz){
        ll d=s[i]-'0';
        rep(j,k+1){
            if(d==0){
                dp1[i+1][j]+=dp1[i][j];
                dp0[i+1][j]+=dp0[i][j];
                if(j+1<=k)dp0[i+1][j+1]+=9*dp0[i][j];
            }
            else{
                if(j+1<=k)dp1[i+1][j+1]+=dp1[i][j];
                if(j+1<=k)dp0[i+1][j+1]+=(d-1)*dp1[i][j];
                dp0[i+1][j]+=dp1[i][j];
                dp0[i+1][j]+=dp0[i][j];
                if(j+1<=k)dp0[i+1][j+1]+=9*dp0[i][j];
            }
        }
    }
    cout << dp0[sz][k]+dp1[sz][k] <<endl;
}