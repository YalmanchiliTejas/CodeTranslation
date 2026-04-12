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
const double EPS=1e-9;
const int inf=1e8;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vi used;
int n,m,out;
vvi G;
void dfs(int a,int b){
	if(b==n-1){
		out++;
		return;
	}
	rep(i,G[a].size())if(used[G[a][i]]==0){
		int to=G[a][i];
		used[to]=true;
		dfs(to,b+1);
		used[to]=false;
	}
}
int main(){
	cin>>n>>m;
	G=vvi(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	used=vi(n);
	used[0]=true;
	dfs(0,0);
	cout<<out<<endl;
}









