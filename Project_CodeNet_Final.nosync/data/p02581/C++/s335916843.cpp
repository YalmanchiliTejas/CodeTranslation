#include <bits/stdc++.h>
using namespace std;
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define chmax(a,b) a=max(a,b)
int n;
int a[6005];
int dp[2005][2005];
void upd(int x,int y,int v){
	chmax(dp[x][y],v);
	chmax(dp[y][x],v);
	chmax(dp[x][n],v);
	chmax(dp[n][x],v);
	chmax(dp[n][y],v);
	chmax(dp[y][n],v);
	chmax(dp[n][n],v);
} 
struct node{
	int x;
	int y;
	int v;
	node(int _x=0,int _y=0,int _v=0):x(_x),y(_y),v(_v){}
};
int main(){
	cin>>n;
	int nn=n*3;
	for(int i=0;i<nn;++i){
		cin>>a[i];
		a[i]--;
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			dp[i][j]=-2e9;
		}
	}
	upd(a[0],a[1],0);
	int cnt=0;
	for(int i=2;i<nn-1;i+=3){
		int x=a[i],y=a[i+1],z=a[i+2];
		if(x==y&&y==z){
			cnt++;
			continue;
		}
		vector<node> v;
		for(int j=0;j<3;++j){
			{
				for(int k=0;k<=n;++k){
					int now=dp[k][n];
					if(y==z){
						chmax(now,dp[k][y]+1);
					}
					v.push_back(node(k,x,now));
				}
			}
			{
				int now=max(dp[n][n],dp[z][z]+1);
				v.push_back(node(x,y,now));
			}
			swap(x,y);
			swap(y,z);
		}
		for(node nd:v){
			int x=nd.x;
			int y=nd.y;
			int v=nd.v;
			upd(x,y,v);
		}
	}
	int ans=dp[n][n];
	int l=a[nn-1];
	chmax(ans,dp[l][l]+1);
	ans+=cnt;
	cout<<ans<<'\n';
	return 0;
}
