#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#define INF 100
using namespace std;

int n;
int h[17],w[17];
int dp[1<<16];
int fie[4][4];
bool ok[4][4][4][4];

int bfs(int s){
	queue<int> que;
	for(int i=0;i<1<<16;i++){
		dp[i]=INF;
	}
	que.push(s);
	dp[s]=0;
	while(que.size()){
		int bit=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				for(int k=i+1;k<=4;k++){
					for(int l=j+1;l<=4;l++){
						if(!ok[i][j][k][l])continue;
						for(int c=0;c<3;c++){
							int nbit=bit;
							for(int x=i;x<k;x++){
								for(int y=j;y<l;y++){
									int nshift=y*4+x;
									if((nbit>>nshift & 1) && fie[x][y]!=c)nbit-=(1<<nshift);
									if(!(nbit>>nshift & 1) && fie[x][y]==c)nbit+=(1<<nshift);
								}
							}
							if(dp[nbit]==INF){
								dp[nbit]=dp[bit]+1;
								que.push(nbit);
							}
						}
					}
				}
			}
		}
	}
	return dp[(1<<16)-1];
}

int main(void){
	scanf("%d",&n);
	memset(ok,false,sizeof(ok));
	for(int i=0;i<n;i++){
		scanf("%d %d",&h[i],&w[i]);
		for(int j=-3;j<4;j++){
			for(int k=-3;k<4;k++){
				int lx=max(0,j);
				int ly=max(0,k);
				int rx=min(4,j+w[i]);
				int ry=min(4,k+h[i]);
				if(lx>=rx || ly>=ry)continue;
				ok[lx][ly][rx][ry]=true;
			}
		}
	}
	for(int i=0;i<4;i++){
		string str;
		cin >> str;
		for(int j=0;j<4;j++){
			if(str[j]=='R')fie[j][i]=0;
			if(str[j]=='G')fie[j][i]=1;
			if(str[j]=='B')fie[j][i]=2;
		}
	}
	printf("%d\n",bfs(0));
	return 0;
}