#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 1e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int s[maxn];
vector<ll> pre[maxn],suf[maxn];
int main()
{
    fastio();
    int n; cin>>n;
    rep(i,0,n-1) cin>>s[i];
    rep(i,1,n-1){
        for(int j=0;j<n;j+=i){
            if(pre[i].size() == 0) pre[i].pb(s[j]);
            else pre[i].pb(pre[i].back() + s[j]);
        }
        for(int j=n-1;j>=0;j-=i){
            if(suf[i].size() == 0) suf[i].pb(s[j]);
            else suf[i].pb(suf[i].back() + s[j]);
        }
    }
    ll ans = 0;
    rep(k,1,n-1){
        for(int d=1;d*k<n-1;d++){
            int A = n-1-k*d;
            int B = A-d;
            if(B <= 0) break;
            if(A%d==0 && A/d<=k) continue;
            ans = max(ans,pre[d][k] + suf[d][k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
