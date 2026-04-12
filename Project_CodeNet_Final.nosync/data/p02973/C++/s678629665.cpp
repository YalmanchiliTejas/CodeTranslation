#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
int n;
vector<ll> a;
const int MAX_N=100010;
ll dp[MAX_N];
const ll INF=1e15;
void solve(){
    fill(dp,dp+n,INF);
    dp[0]=a[0];
    rep(i,1,n){
        if(*(upper_bound(dp,dp+n,a[i])-1)==a[i]) *upper_bound(dp,dp+n,a[i])=a[i];
        else *lower_bound(dp,dp+n,a[i])=a[i];
    }
    cout<<lower_bound(dp,dp+n,INF)-dp<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    a.resize(n);
    rep(i,0,n) cin>>a[n-1-i];
    ll ans=1;
    ll res=a[0];
    rep(i,1,n){
        if(a[i]>=res){
            ans++;
            res=a[i];
        }
    }
    solve();
}