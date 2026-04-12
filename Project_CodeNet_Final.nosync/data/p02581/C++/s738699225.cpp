#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define y1 yyyy1111
using namespace std;
int dp[2005][2005],maxi[2005],lst[2005][2005],ma;
V<P<int,int> > v;
void ch(int x,int y,int x1,int y1,int p){
	if(x>y)swap(x,y);
	if(x1>y1)swap(x1,y1);
	gmax(dp[x][y],lst[x1][y1]+p);
	v.PB(MP(x,y));
}
void sol(int x,int y,int y1){
	if(x>y)swap(x,y);
	gmax(dp[x][y],y1);
	v.PB(MP(x,y));
}
void kk(){
	for(auto u:v){
		gmax(maxi[u.F],dp[u.F][u.S]);
		gmax(maxi[u.S],dp[u.F][u.S]);
		gmax(ma,dp[u.F][u.S]);
	}
	v.clear();
}
void p(int x,int y){
	if(x>y)swap(x,y);
	lst[x][y]=dp[x][y];
}
int a[6005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,3*n)cin>>a[i];
	FOR(i,1,n)FOR(j,i,n)dp[i][j]=-1e9;
	FOR(i,1,n)maxi[i]=-1e9;
	ch(a[1],a[2],0,0,0);kk();
	int cnt=0;
	rep(i,1,n){
		int s[3];
		rep(j,0,3)s[j]=a[i*3+j];
		FOR(j,1,n){
			p(j,s[0]);p(j,s[1]);p(j,s[2]);
		}
		sort(s,s+3);
		if(s[0]==s[1]&&s[1]==s[2]){
			cnt++;continue;
		}
		if(s[0]==s[1]){
			ch(s[0],s[1],s[2],s[2],1);
			FOR(j,1,n){
				ch(s[2],j,j,s[0],1);
			}
		}else if(s[1]==s[2]){
			ch(s[1],s[2],s[0],s[0],1);
			FOR(j,1,n){
				ch(s[0],j,j,s[1],1);
			}
		}else{
			ch(s[1],s[2],s[0],s[0],1);
			ch(s[0],s[2],s[1],s[1],1);
			ch(s[0],s[1],s[2],s[2],1); 
		}
		FOR(j,1,n){
			rep(k,0,3){
				sol(j,s[k],maxi[j]);
			}
		}
		rep(j,0,3){
			rep(k,j+1,3){
				sol(s[j],s[k],ma);
			}
		}
		kk(); 
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,i,n)gmax(ans,dp[i][j]);
	} 
	gmax(ans,dp[a[3*n]][a[3*n]]+1);
	cout<<ans+cnt;
	RE 0;
}
