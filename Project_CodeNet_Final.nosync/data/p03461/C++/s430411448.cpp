#include<iostream>
#include<algorithm>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=15;
const int maxm=101;
int a,b;
int d[maxn][maxn],e[maxm][maxm];
int main(){
	scanf("%d%d",&a,&b);
	for(register int i=1;i<=a;i++){
		for(register int j=1;j<=b;j++)
			scanf("%d",&d[i][j]);
	}
	for(register int i=0;i<maxm;i++){
		for(register int j=0;j<maxm;j++){
			for(register int x=1;x<=a;x++){
				for(register int y=1;y<=b;y++){
					e[i][j]=max(e[i][j],d[x][y]-i*x-j*y);
				}
			}
		}
	}
	for(register int x=1;x<=a;x++){
		for(register int y=1;y<=b;y++){
			int tmp=maxm;
			for(register int i=0;i<maxm;i++){
				for(register int j=0;j<maxm;j++){
					tmp=min(tmp,e[i][j]+i*x+j*y);
				}
			}
			if(tmp!=d[x][y]){
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	}
	cout<<"Possible"<<endl;
	cout<<2*maxm<<' '<<2*(maxm-1)+maxm*maxm<<endl;
	for(register int i=1;i<maxm;i++){
		printf("%d %d X\n",i,i+1);
		printf("%d %d Y\n",maxm+i,maxm+i+1);
	}
	for(register int i=0;i<maxm;i++){
		for(register int j=0;j<maxm;j++){
			printf("%d %d %d\n",i+1,2*maxm-j,e[i][j]);
		}
	}
	printf("1 %d\n",2*maxm);
}