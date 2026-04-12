#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())

	
bool g[256][256];


int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void dfs(int y,int x){
	if(y<0||256<=y||x<0||256<=x||g[y][x])return;
	g[y][x]=true;
	rep(i,4){
		dfs(y+dy[i],x+dx[i]);
	}
}

int main(){
	int n;
	int l[50],t[50],r[50],b[50];
	while(cin>>n,n){
		vector<int> vx,vy;
		vx.push_back(-1);
		vy.push_back(-1);
		rep(i,n){
			cin>>l[i]>>t[i]>>r[i]>>b[i];
			l[i]*=2;
			t[i]*=2;
			r[i]*=2;
			b[i]*=2;
			vx.push_back(l[i]);vx.push_back(l[i]+1);
			vy.push_back(t[i]);vy.push_back(t[i]+1);
			vx.push_back(r[i]);vx.push_back(r[i]+1);
			vy.push_back(b[i]);vy.push_back(b[i]+1);
		}
		sort(all(vx));
		uniq(vx);
		sort(all(vy));
		uniq(vy);
		memset(g,false,sizeof(g));
		rep(i,n){
			int x1,y1,x2,y2;
			x1=lower_bound(all(vx),l[i])-vx.begin();
			y2=lower_bound(all(vy),t[i])-vy.begin();
			x2=lower_bound(all(vx),r[i])-vx.begin();
			y1=lower_bound(all(vy),b[i])-vy.begin();
			for(int j=y1;j<=y2;j++)g[j][x1]=g[j][x2]=true;
			for(int j=x1;j<=x2;j++)g[y1][j]=g[y2][j]=true;
		}
		int c=0;
		rep(i,256){
			rep(j,256){
				if(g[i][j])continue;
				c++;
				dfs(i,j);
			}
		}
		cout<<c<<endl;
	}
	return 0;
}