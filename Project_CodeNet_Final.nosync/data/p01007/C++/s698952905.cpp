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
#include<cstdio>
#include<sstream>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int t,n;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vvi in;
bool check(int a,int b){return a>=0&&b>=0&&a<n&&b<n;}
void f(int a,int b){
	in[a][b]^=1;
	rep(i,4){
		int nx=a+dx[i];
		int ny=b+dy[i];
		if(!check(nx,ny))continue;
		if(in[nx][ny]==t)f(nx,ny);
	}
}
int main(){
	int m;
	cin>>n>>m;
	in=vvi(n,vi(n));
	rep(i,n)rep(j,n)cin>>in[i][j];
	while(m--){
		int q;
		cin>>q;
		if(q==0){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			a--;b--;
			d/=90;
			while(d--){
				vvi tmp=in;
				rep(i,c)rep(j,c)tmp[i+a][j+b]=in[a+c-j-1][b+i];
				in=tmp;
			}
		}else if(q==1){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			rep(i,c)rep(j,c)in[i+a][j+b]^=1;
		}else if(q==2){
			int a;
			cin>>a;
			a--;
			in[a].pb(in[a][0]);
			in[a].erase(in[a].begin());
		}else if(q==3){
			int a;cin>>a;a--;
			in[a].insert(in[a].begin(),in[a][n-1]);
			in[a].erase(in[a].end()-1);
		}else if(q==4){
			int a,b;
			cin>>a>>b;a--;b--;
			t=in[a][b];
			f(a,b);
		}
	}
	rep(i,n){cout<<in[i][0];rep(j,n-1)cout<<" "<<in[i][j+1];cout<<endl;}
}