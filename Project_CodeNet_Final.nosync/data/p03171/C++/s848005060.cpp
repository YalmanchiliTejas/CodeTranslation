//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define chalavo continue
#define basHo break
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int n;
lli arr[3003];
lli dp[3003][3003][2];
int vis[3003][3003][2];
lli fn(int i,int j,int turn) {
	if(i>j) return 0;
	if(vis[i][j][turn]) return dp[i][j][turn];
	vis[i][j][turn]=1;
	if(turn) { //taro
		lli first=arr[i]+fn(i+1,j,1-turn);
		lli last=arr[j]+fn(i,j-1,1-turn);
		return dp[i][j][turn]=max(first,last);
	}
	else { //jiro
		lli first=fn(i+1,j,1-turn);
		lli last=fn(i,j-1,1-turn);
		return dp[i][j][turn]=min(first,last);
	}
}
int main(){
	jaldiKarNe;
	lli sum=0;
	cin>>n;
	fr(i,1,n) cin>>arr[i],sum+=arr[i];
	lli taro=fn(1,n,1);
	lli jiro=sum-taro;
	cout<<taro-jiro;
}
