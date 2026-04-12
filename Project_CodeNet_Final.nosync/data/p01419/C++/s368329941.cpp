#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w;
char B[50][51];

vector< pair<int,int> > get_path(int x0,int y0,int x1,int y1){
	bool vis[50][50]={};
	vis[y0][x0]=true;
	static pair<int,int> pre[50][50];

	int head=0,tail=0;
	static pair<int,int> Q[50*50];
	Q[tail++]=make_pair(y0,x0);
	while(head<tail){
		int y=Q[head].first,x=Q[head].second; head++;
		rep(k,4){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && B[yy][xx]=='.' && !vis[yy][xx]){
				vis[yy][xx]=true;
				Q[tail++]=make_pair(yy,xx);
				pre[yy][xx]=make_pair(y,x);
			}
		}
	}

	int y=y1,x=x1;
	vector< pair<int,int> > P(1,make_pair(y1,x1));
	while(y!=y0 || x!=x0){
		pair<int,int> tmp=pre[y][x];
		P.push_back(tmp);
		y=tmp.first;
		x=tmp.second;
	}
	reverse(P.begin(),P.end());
	P.pop_back();
	return P;
}

int main(){
	int n; scanf("%d%d%d",&h,&w,&n);
	rep(i,h) scanf("%s",B[i]);
	int left[50][50],on[50][50],off[50][50];
	rep(i,h) rep(j,w) scanf("%d",left[i]+j);
	rep(i,h) rep(j,w) scanf("%d",on[i]+j);
	rep(i,h) rep(j,w) scanf("%d",off[i]+j);

	vector<int> reach[50][50]; // reach[i][j] := ( マス (i,j) を通る時刻の列 )
	int t=0;
	int y0,x0; scanf("%d%d",&y0,&x0);
	rep(i,n-1){
		int y1,x1; scanf("%d%d",&y1,&x1);
		vector< pair<int,int> > P=get_path(x0,y0,x1,y1);
		rep(j,P.size()){
			reach[P[j].first][P[j].second].push_back(t++);
		}
		x0=x1; y0=y1;
	}
	reach[y0][x0].push_back(t++);

	int ans=0;
	rep(i,h) rep(j,w) {
		int m=reach[i][j].size();
		if(m>0){
			ans+=on[i][j];
			rep(k,m-1){
				int d=reach[i][j][k+1]-reach[i][j][k];
				ans+=min(off[i][j]+on[i][j],d*left[i][j]);
			}
			ans+=off[i][j];
		}
	}
	printf("%d\n",ans);

	return 0;
}