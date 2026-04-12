#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(s) s.begin(),s.end()
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;

vector<int>a(3005);
bool f[3005][3005]={};
int dp[3005][3005];
int d(int l,int r){
    if(f[l][r]){return dp[l][r];}
    f[l][r]=1;
    if(l==r){return dp[l][r]=a[l];}
    return dp[l][r]=max(a[l]-d(l+1,r),a[r]-d(l,r-1));
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
    }
    int ans = d(1,n);
    cout<<ans<<endl;
}