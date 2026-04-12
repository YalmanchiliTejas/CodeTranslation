#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int t;
bool ok[32][32];
string f[4];
int dp[(1<<16)];
int dfs(int mask){
	if(dp[mask] < 1e8) return dp[mask];
	if(mask == (1<<16)-1) return 0;
	for(int i=-3;i<4;i++){
		for(int ii=i;ii<7;ii++){
			for(int j=-3;j<4;j++){
				for(int jj=j;jj<7;jj++){
					if(!ok[ii-i+1][jj-j+1]) continue;
					int check = 0;
					int go = 0;
					for(int a=i;a<=ii;a++) for(int b=j;b<=jj;b++){
					    if(0<=a&&a<4&&0<=b&&b<4);else continue;
						int c = a*4+b;
						if(((mask>>c) & 1) == 0){
							if(f[a][b] == 'R') check|=1,go+=(1<<c);
							if(f[a][b] == 'G') check|=2,go+=(1<<c);
							if(f[a][b] == 'B') check|=4,go+=(1<<c);
						}
					}
					if(__builtin_popcount(check) == 1) dp[mask] = min(dp[mask],dfs(mask+go)+1);
				}
			}
		}
	}
	return dp[mask];
}
int main(){
	cin>>t;
	rep(i,t){
		int a,b; cin>>a>>b;
		ok[a][b] = 1;
	}
	rep(i,4) cin>>f[i];
	fill(dp,dp+(1<<16),INF);
	cout << dfs(0) << endl;
}
