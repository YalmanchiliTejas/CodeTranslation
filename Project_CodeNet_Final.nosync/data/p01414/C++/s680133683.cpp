#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int p[20];
int q[20];
char str[5][5];
int bfs[1<<16];
char col[5]="RGB";
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%d",p+i,q+i);
	}
	for(int i=0;i<4;i++)scanf("%s",str[i]);
	for(int i=0;i<(1<<16);i++)bfs[i]=-1;
	bfs[0]=0;
	queue<int>Q;
	Q.push(0);
	while(Q.size()){
		if(~bfs[(1<<16)-1])break;
		int at=Q.front();
		Q.pop();
		for(int i=0;i<a;i++){
			for(int j=-p[i]+1;j<4;j++){
				for(int k=-q[i]+1;k<4;k++){
					for(int c=0;c<3;c++){
						int to=at;
						for(int l=max(0,-j);l<min(p[i],4-j);l++)for(int m=max(0,-k);m<min(q[i],4-k);m++){
							//if(j+l<0||k+m<0||j+l>3||k+m>3)continue;
							if(str[j+l][k+m]==col[c])to|=(1<<((j+l)*4+k+m));
							else to&=(~(1<<((j+l)*4+k+m)));
						}
						if(!~bfs[to]){
							bfs[to]=bfs[at]+1;
							Q.push(to);
						}
					}
				}
			}
		}
	}
	printf("%d\n",bfs[(1<<16)-1]);
}