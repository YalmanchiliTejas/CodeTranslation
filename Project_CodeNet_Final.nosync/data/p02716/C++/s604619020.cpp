#include<bits/stdc++.h>
using namespace std;
#define int   long long
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define m 1000000000000000007LL
int n,a[200005],dp[200005][4][2];
bool vis[200005][4][2];
int f(int pos,int cnt,int last){
	if(cnt<-1) return -m;
	if(pos==n) return 0;
	if(vis[pos][cnt+2][last]) return dp[pos][cnt+2][last];
	vis[pos][cnt+2][last]=1;
	int &ans=dp[pos][cnt+2][last];
	ans=f(pos+1,cnt-1,0);
	if(last==0) ans=max(ans,f(pos+1,cnt+1,1)+a[pos]);
	return ans;
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    cout<<f(0,n%2,0)<<endl;
}
 
signed main(){
	solve();
	
	
	
}