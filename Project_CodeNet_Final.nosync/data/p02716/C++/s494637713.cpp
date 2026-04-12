#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[200005],dp[200005][4][2];
bool vis[200005][4][2];
int go(int pos,int cnt,int last){
	if(cnt<-1) return -hell;
	if(pos==n) return 0;
	if(vis[pos][cnt+2][last]) return dp[pos][cnt+2][last];
	vis[pos][cnt+2][last]=1;
	int &ans=dp[pos][cnt+2][last];
	ans=go(pos+1,cnt-1,0);
	if(last==0) ans=max(ans,go(pos+1,cnt+1,1)+a[pos]);
	return ans;
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    cout<<go(0,n%2,0)<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}