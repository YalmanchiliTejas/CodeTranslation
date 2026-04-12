#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-5;
const int inf=1e8;
int n,m,x;
vvi in;
vs fil;
vvi info;
vp task;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(){
	cin>>n>>m>>x;
	in=vvi(n*m);
	fil=vs(n);
	rep(i,n)cin>>fil[i];
	info=vvi(n*m,vi(3));
	rep(j,3)rep(i,n*m)cin>>info[i][j];
	task=vp(x);
	rep(i,x)cin>>task[i].first>>task[i].second;
	int tim=0;
	rep(i,x-1){
		vvi used(n,vi(m,inf));
		used[task[i].first][task[i].second]=0;
		priority_queue<pii>q;
		q.push(pii(task[i].first,task[i].second));
		while(!q.empty()){
			pii p=q.top();
			q.pop();
			rep(i,4){
				int nx=p.first+dx[i];
				int ny=p.second+dy[i];
				if(nx<0||ny<0||nx>=n||ny>=m||fil[nx][ny]=='#')continue;
				if(used[nx][ny]>1+used[p.first][p.second]){
					used[nx][ny]=1+used[p.first][p.second];
					q.push(pii(nx,ny));
				}
			}
		}
		int t=used[task[i+1].first][task[i+1].second],tmp=t;
		int x=task[i+1].first,y=task[i+1].second;
		while(t){
			rep(i,4){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<0||ny<0||nx>=n||ny>=m||fil[nx][ny]=='#')continue;
				if(used[x][y]!=used[nx][ny]+1)continue;
				t--;
				in[nx*m+ny].pb(tim+t);
				x=nx;y=ny;
				break;
			}
		}
		tim+=tmp;
	}
	in[task[x-1].first*m+task[x-1].second].pb(tim);
	int out=0;
	rep(i,n*m)if(in[i].size()){
		out+=info[i][1]+info[i][2];
		rep(j,in[i].size()-1)out+=min((in[i][j+1]-in[i][j])*info[i][0],info[i][1]+info[i][2]);
	}
	cout<<out<<endl;
}