#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(n,v) cout<<#v<<":";for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int n;
ll a[3001];
ll dp[3001][3001];
bool f[3001][3001];
ll solve(int l,int r){
    if(f[l][r]) return dp[l][r];
    f[l][r]=true;
    if((l+n-1-r)%2==0){
        if(l==r) return dp[l][r]=a[l];
        return dp[l][r]=max(a[l]+solve(l+1,r),a[r]+solve(l,r-1));
    }
    else{
        if(l==r) return dp[l][r]=-a[l];
        return dp[l][r]=min(solve(l+1,r)-a[l],solve(l,r-1)-a[r]);
    }
}
int main(){
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    solve(0,n-1);
    cout<<dp[0][n-1]<<endl;
    return 0;
}