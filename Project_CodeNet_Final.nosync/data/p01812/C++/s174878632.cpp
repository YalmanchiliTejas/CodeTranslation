#include <bits/stdc++.h>
#define range(i, a, n) for(int (i) = (a); (i) < (n); (i)++)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
 
const int inf=1<<16;
 
int mov[1<<16][110];
 
int n,m,k;
int d[20];
int v[110][110];
 
int dp[1<<16];
 
 
inline void calc(int p){
	int vec[18],vec2[18];
	int mat[18][18];
	rep(i,m+1) vec[i]=0;
	rep(i,m+1)rep(j,m+1) mat[i][j]=0;	
	rep(i,m){
		int to=v[d[i]][p];
		int in=m;
		rep(j,m) if(to==d[j]) in=j;
		mat[i][in]=1;
	}
	rep(i,m) vec[i]=1<<i,vec2[i]=0;
	rep(i,m) rep(j,m) if(mat[i][j]) vec2[i]|=vec[j];
	rep(mask,1<<m)rep(i,m) if(mask&vec2[i]) mov[mask][p]|=(1<<i);
	return ;
}
 
typedef pair<int,int> pii;
 
int main(void){
	cin >> n >> m >> k;
	rep(i,m) cin >> d[i],d[i]--;
	rep(i,n)rep(j,k) cin >> v[i][j],v[i][j]--;
	
	rep(i,k) calc(i);	
 
	rep(i,1<<m) dp[i]=inf;
	dp[(1<<m)-1]=0;
	queue<pii> q;
	q.push(make_pair(0,(1<<m)-1));	
	while(!q.empty()){
		pii cur=q.front();q.pop();
		// cerr  << cur.first << " " << cur.second << endl;
		rep(i,k) if(dp[mov[cur.second][i]]>cur.first+1){
			dp[mov[cur.second][i]]=cur.first+1;
			q.push(make_pair(cur.first+1,mov[cur.second][i]));
		}
	}
	//rep(mask,1<<m)rep(i,k) cerr << mov[mask][i] << endl;
	//rep(i,1<<m) cerr << dp[i] << endl;
	cout << dp[0] << endl;
	return 0;
}