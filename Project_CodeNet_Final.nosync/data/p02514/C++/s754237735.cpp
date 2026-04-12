#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define rp(i,c) rep(i,(c).size())
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf=1<<28;
const double INF=1e12,EPS=1e-9;

const int dy[]={-1,0,1,0},dx[]={0,-1,0,1};
string maze[100][101];

int dp[100][100];

int main()
{
	int h,w;
	while(cin>>w>>h,w){
		int sy,sx,gy,gx,maxtama=0;
		rep(i,h)rep(j,w){
			cin>>maze[i][j];
			if(maze[i][j]=="S")sy=i, sx=j;
			if(maze[i][j]=="G")gy=i, gx=j;
			if(isdigit(maze[i][j][0]))maxtama=max(maxtama,atoi(maze[i][j].c_str()));
		}
		vector<vi> tamas(maxtama+2);
		rep(i,h)rep(j,w)if(isdigit(maze[i][j][0])){
			int num=atoi(maze[i][j].c_str());
			tamas[num].pb(i*w+j);
		}
		tamas[0].pb(sy*w+sx);
		tamas[maxtama+1].pb(gy*w+gx);
		
		vector<vi> dp(maxtama+2);
		rep(i,maxtama+2){
			dp[i].resize(tamas[i].size());
			rep(j,dp[i].size())dp[i][j]=inf;
		}
		
		dp[0][0]=0;
		rep(i,maxtama+1)rep(j,dp[i].size())rep(k,dp[i+1].size()){
			dp[i+1][k]=min(dp[i+1][k],dp[i][j]+
				abs(tamas[i][j]/w-tamas[i+1][k]/w)+abs(tamas[i][j]%w-tamas[i+1][k]%w));
		}
		cout<<dp[maxtama+1][0]<<endl;
		
		/*
		queue<pi> q;
		set<pi> v;
		q.push(mp(0,sy*100+sx));
		while(!q.empty()){
			int y=q.front().second%10000/100, x=q.front().second%100;
			int cost=q.front().first, tama=q.front().second/10000; q.pop();
			
			if(v.count(mp(cost,tama*10000+y*100+x)))continue;
			v.insert(mp(cost,tama*10000+y*100+x));
			if(tama==maxtama&&maze[y][x]=="G"){
				cout<<cost<<endl; break;
			}
			
			rep(d,4){
				int ny=y+dy[d], nx=x+dx[d],ntama=tama;
					if(0<=ny&&ny<h&&0<=nx&&nx<w){
						if(isdigit(maze[ny][nx][0])&&atoi(maze[ny][nx].c_str())==tama+1)ntama++;
						q.push(mp(cost+1,ntama*10000+ny*100+nx));
					}
			}
		}
		*/
	}
	
	return 0;
}