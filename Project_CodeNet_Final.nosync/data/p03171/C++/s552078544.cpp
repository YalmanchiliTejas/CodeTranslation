#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;(i)--)
#define rrep1(i,n) for(int i=((int)(n));i>0;(i)--)
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PP;
const int MAX=1e5+10;
const ll INF=1e18;

int N;
ll a[3010];
void input(){
    cin>>N;
    rep(i,N)cin>>a[i];
}

ll dp[3010][3010];
ll dfs(int l, int r, int f){
    if(dp[l][r]!=INF)return dp[l][r];
    if(l==r){
        dp[l][r]=0;
        return 0;
    }
    if(f==1){
        dp[l][r]=max(dfs(l,r-1,-f)+a[r-1], dfs(l+1, r, -f)+a[l]);
        return dp[l][r];
    }
    else{
        dp[l][r]=min(dfs(l,r-1,-f)-a[r-1], dfs(l+1, r, -f)-a[l]);
        return dp[l][r];
    }
}

ll ans;
void solve(){
  	rep(l,N+1)rep(r,N+1)if(l<=r)dp[l][r]=INF;
    ans=dfs(0,N,1);
}

void output(){
    cout<<ans<<endl;
}

int main(){
    input();
    solve();
    output();
}