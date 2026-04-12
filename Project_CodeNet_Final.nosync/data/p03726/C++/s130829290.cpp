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
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mt make_tuple
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<string,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
typedef vector<vd> vvd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-7;
const int inf=1e9;
const ll INF=2e18;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n;
vi used;
bool H=false;
vvi G;
int dfs(int a){
	used[a]=true;
	int co=0;
	rep(i,G[a].size())if(used[G[a][i]]==0&&dfs(G[a][i]))co++;
	if(co>=2){
		H=true;
		return 0;
	}else if(co==1)return 0;
	else return 1;
}
int main(){
	cin>>n;
	G=vvi(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	used=vi(n);
	int t=dfs(0);
	if(t||H)cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}




