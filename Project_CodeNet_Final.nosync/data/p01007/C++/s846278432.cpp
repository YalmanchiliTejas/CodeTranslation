#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int mat[20][20];
int to[20][20];
int v[20][20];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)for(int j=0;j<a;j++)scanf("%d",&mat[i][j]);
	while(b--){
		int o;scanf("%d",&o);
		for(int i=0;i<a;i++)for(int j=0;j<a;j++)to[i][j]=mat[i][j];
		if(o==0){
			int r,c,sz,th;
			scanf("%d%d%d%d",&r,&c,&sz,&th);
			r--;c--;
			if(th==90){
				for(int i=0;i<sz;i++)for(int j=0;j<sz;j++){
					to[r+j][c+sz-1-i]=mat[r+i][c+j];
				}
			}else if(th==180){
				for(int i=0;i<sz;i++)for(int j=0;j<sz;j++){
					to[r+i][c+j]=mat[r+sz-1-i][c+sz-1-j];
				}
			}else if(th==270){
				for(int i=0;i<sz;i++)for(int j=0;j<sz;j++){
					to[r+sz-1-j][c+i]=mat[r+i][c+j];
				}
			}
		}else if(o==1){
			int r,c,sz;
			scanf("%d%d%d",&r,&c,&sz);r--;c--;
			for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)to[r+i][c+j]=!to[r+i][c+j];
		}else if(o==2){
			int r;scanf("%d",&r);r--;
			for(int i=0;i<a-1;i++)to[r][i]=mat[r][i+1];
			to[r][a-1]=mat[r][0];
		}else if(o==3){
			int r;scanf("%d",&r);r--;
			for(int i=0;i<a-1;i++)to[r][i+1]=mat[r][i];
			to[r][0]=mat[r][a-1];
		}else{
			int r,c;scanf("%d%d",&r,&c);r--;c--;
			queue<pair<int,int> >Q;
			int color=to[r][c];
			for(int i=0;i<a;i++)for(int j=0;j<a;j++)v[i][j]=0;
			v[r][c]=1;
			Q.push(make_pair(r,c));
			while(Q.size()){
				int row=Q.front().first;
				int col=Q.front().second;
				Q.pop();
				for(int i=0;i<4;i++){
					if(0<=row+dx[i]&&row+dx[i]<a&&0<=col+dy[i]&&col+dy[i]<a&&!v[row+dx[i]][col+dy[i]]&&color==to[row+dx[i]][col+dy[i]]){
						v[row+dx[i]][col+dy[i]]=1;
						Q.push(make_pair(row+dx[i],col+dy[i]));
					}
				}
			}
			for(int i=0;i<a;i++)for(int j=0;j<a;j++)if(v[i][j])to[i][j]=!to[i][j];
		}
		for(int i=0;i<a;i++)for(int j=0;j<a;j++)mat[i][j]=to[i][j];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(j)printf(" ");printf("%d",mat[i][j]);
		}
		printf("\n");
	}
}