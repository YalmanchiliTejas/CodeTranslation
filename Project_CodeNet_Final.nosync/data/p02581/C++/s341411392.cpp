#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>piii;
const int maxn=2010;
int n,n3;
int a[3*maxn],b[maxn];
int dp[maxn][maxn];
int ans,ans2;
vector<piii>vis;
void update(int i,int j,int k){
	vis.pb(mp(mp(i,j),k));
	vis.pb(mp(mp(j,i),k));
}
void init(){
	memset(b,-0x3f,sizeof b);
	memset(dp,-0x3f,sizeof dp);
	dp[a[1]][a[2]]=b[a[1]]=b[a[2]]=ans2;
}
void solve(){
	for(int i=3;i<=n3;i+=3,vis.clear()){
		if(a[i]==a[i+1]&&a[i]==a[i+2]){
			ans2--;
			continue;
		}
		for(int _=0;_<3;_++){
			swap(a[i],a[i+1]),swap(a[i+1],a[i+2]);
			update(a[i],a[i+1],max(ans,dp[a[i+2]][a[i+2]]+1));
			for(int j=1;j<=n;j++){
				if(a[i+1]==a[i+2])update(j,a[i],dp[j][a[i+1]]+1);
				update(j,a[i],b[j]);
			}
		}
		for(auto j:vis){
			int e=j.F.F;
			int f=j.F.S;
			int g=j.S;
			dp[e][f]=max(dp[e][f],g);
			b[e]=max(b[e],g);
			ans=max(ans,g);
		}
	}
}
int main(){
	cin>>n;
	n3=3*n;
	for(int i=1;i<=n3;i++)cin>>a[i];
	init();
	solve();
	cout<<ans-ans2<<endl;
	return 0;
}
