#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int n;
vector<int> xid,yid;
int fie[401][401];
int l[51],r[51],t[51],b[51];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(int x,int y){
	queue <P> que;
	que.push(P(x,y));
	fie[x][y]=1;
	while(que.size()){
		P q=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			int nx=q.first+dx[i],ny=q.second+dy[i];
			if(nx>=0 && nx<400 && ny>=0 && ny<400){
				if(fie[nx][ny]==0){
					fie[nx][ny]=1;
					que.push(P(nx,ny));
				}
			}
		}
	}
}

int main(void){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		xid.clear();
		yid.clear();
		memset(fie,0,sizeof(fie));
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d",&l[i],&t[i],&r[i],&b[i]);
			l[i]*=2;
			r[i]*=2;
			t[i]*=2;
			b[i]*=2;
			for(int j=-1;j<=1;j++){
				xid.push_back(l[i]+j);
				xid.push_back(r[i]+j);
				yid.push_back(t[i]+j);
				yid.push_back(b[i]+j);
			}
		}
		sort(xid.begin(),xid.end());
		xid.erase(unique(xid.begin(),xid.end()),xid.end());
		sort(yid.begin(),yid.end());
		yid.erase(unique(yid.begin(),yid.end()),yid.end());
		for(int i=0;i<n;i++){
			int id=lower_bound(xid.begin(),xid.end(),l[i])-xid.begin();
			l[i]=id;
			id=lower_bound(xid.begin(),xid.end(),r[i])-xid.begin();
			r[i]=id;
			id=lower_bound(yid.begin(),yid.end(),t[i])-yid.begin();
			t[i]=id;
			id=lower_bound(yid.begin(),yid.end(),b[i])-yid.begin();
			b[i]=id;
			for(int j=l[i];j<=r[i];j++){
				fie[j][t[i]]=-1;
				fie[j][b[i]]=-1;
			}
			for(int j=b[i];j<=t[i];j++){
				fie[l[i]][j]=-1;
				fie[r[i]][j]=-1;
			}
		}
		int cnt=0;
		for(int i=0;i<400;i++){
			for(int j=0;j<400;j++){
				if(fie[i][j]==0){
					bfs(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}