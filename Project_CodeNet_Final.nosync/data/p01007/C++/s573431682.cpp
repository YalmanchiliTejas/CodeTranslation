#include<iostream>
#include<vector>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t,n,m;
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
	cin>>n>>m;
	in=vvi(n,vi(n));
	rep(i,n)rep(j,n)cin>>in[i][j];
	while(m--){
		int q;
		cin>>q;
		int a,b,c,d;
		if(q==0){
			cin>>a>>b>>c>>d;
			a--;b--;
			rep(i,d/90){
				vvi tmp=in;
				rep(i,c)rep(j,c)tmp[i+a][j+b]=in[a+c-j-1][b+i];
				in=tmp;
			}
		}else if(q==1){
			cin>>a>>b>>c;
			a--;b--;
			rep(i,c)rep(j,c)in[i+a][j+b]^=1;
		}else if(q==2){
			cin>>a;
			a--;
			in[a].pb(in[a][0]);
			in[a].erase(in[a].begin());
		}else if(q==3){
			cin>>a;a--;
			in[a].insert(in[a].begin(),in[a][n-1]);
			in[a].erase(in[a].end()-1);
		}else if(q==4){
			cin>>a>>b;a--;b--;
			t=in[a][b];
			f(a,b);
		}
	}
	rep(i,n){cout<<in[i][0];rep(j,n-1)cout<<" "<<in[i][j+1];cout<<endl;}
}