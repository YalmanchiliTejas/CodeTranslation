#include<bits/stdc++.h>
using namespace std;
const int maxn=2009;
const int inf=1e9;

int n;

int f[maxn][maxn];
int mxr[maxn];

struct state{
	int x,y,a;
	state(int _x=0,int _y=0,int _a=0){
		x=_x;y=_y;a=_a;
	}
};
vector<state>update;
void trans1(int x,int y,int z){
	update.push_back(state(y,z,f[x][x]+1));
}
void trans2(int x,int y,int z){
	for(int i=1;i<=n;++i){
		update.push_back(state(i,z,f[i][x]+1));
	}
}
void trans3(int x){
	for(int i=1;i<=n;++i){
		update.push_back(state(i,x,mxr[i]));
	}
}
void trans4(int x,int y){
	int mx=-inf;
	for(int i=1;i<=n;++i)mx=max(mx,mxr[i]);
	update.push_back(state(x,y,mx));
}

int cnt,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		mxr[i]=-inf;
		for(int j=1;j<=n;++j){
			f[i][j]=-inf;
		}
	}
	int x,y,z;scanf("%d%d",&x,&y);
	f[x][y]=f[y][x]=0;mxr[x]=mxr[y]=0;
	
	for(int i=3;i+2<=3*n;i+=3){
		scanf("%d%d%d",&x,&y,&z);
		if(x==y&&x==z){
			++cnt;continue;
		}
		
		trans1(x,y,z);
		trans1(y,x,z);
		trans1(z,x,y);
		if(x==y)trans2(x,y,z);
		if(x==z)trans2(x,z,y);
		if(y==z)trans2(y,z,x);
		
		trans3(x);
		trans3(y);
		trans3(z);
		
		trans4(x,y);
		trans4(x,z);
		trans4(y,z);
		
		for(int j=0;j<update.size();++j){
			int x=update[j].x,y=update[j].y,a=update[j].a;
			f[x][y]=max(f[x][y],a);
			f[y][x]=max(f[y][x],a);
			mxr[x]=max(mxr[x],a);
			mxr[y]=max(mxr[y],a);
		}
		update.clear();
	}
	
	scanf("%d",&x);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==x&&j==x)ans=max(ans,cnt+f[i][j]+1);
			else ans=max(ans,cnt+f[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}