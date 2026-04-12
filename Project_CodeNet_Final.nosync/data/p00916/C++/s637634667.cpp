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
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int N,M;
vvi field;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y){
	field[x][y]=1;
	rep(i,4){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=M||field[nx][ny])continue;
		dfs(nx,ny);
	}
}
int main(){
	int n;
	while(cin>>n,n){
		vi x,y;
		vvi in(n,vi(4));
		rep(i,n)rep(j,4){
			cin>>in[i][j];
			in[i][j]*=2;
			loop(k,-1,2)if(j%2){
				y.pb(in[i][j]+k);
			}else{
				x.pb(in[i][j]+k);
			}
		}
		sort(all(x));
		sort(all(y));
		x.erase(unique(all(x)),x.end());
		y.erase(unique(all(y)),y.end());
		rep(i,n)rep(j,4)if(j%2==0)in[i][j]=lower_bound(all(x),in[i][j])-x.begin();
						else in[i][j]=lower_bound(all(y),in[i][j])-y.begin();
		N=x.size();
		M=y.size();
		field=vvi(N,vi(M));
		rep(i,n){
			loop(j,in[i][0],in[i][2]+1)field[j][in[i][1]]=field[j][in[i][3]]=1;
			loop(j,in[i][3],in[i][1]+1)field[in[i][0]][j]=field[in[i][2]][j]=1;
		}
		int out=0;
		rep(i,N)rep(j,M)if(field[i][j]==0){
			out++;
			dfs(i,j);
		}
		cout<<out<<endl;
	}
}