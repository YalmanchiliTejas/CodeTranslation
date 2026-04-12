#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
ll n;
vector<vector<ll> >dp(3010,vector<ll>(3010,-1));
vector<ll>a(3010);
ll solve(ll x,ll y){
    if(x>y)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    ll t=(n-y-x+1)%2;
    ll res;
    if(t){
        res=min(solve(x+1,y)-a[x],solve(x,y-1)-a[y]);
    }else{
        res=max(solve(x+1,y)+a[x],solve(x,y-1)+a[y]);
    }
    dp[x][y]=res;
    return res;
}
int main(){
    cin>>n;
    rep(i,n)cin>>a[i];
    ll ans=solve(0,n-1);
    cout<<ans<<endl;
}