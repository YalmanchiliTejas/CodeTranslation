#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)

int main(){
	int a,b;
	int d[12][12];
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			scanf("%d",&d[i][j]);
		}
	}
	
	bool ok[12][12];
	memset(ok,0,sizeof ok);
	for(int s=0;s<=100;s++){
		for(int t=0;t<=100;t++){
			int u=0;
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					chmax(u,d[i][j]-s*i-t*j);
				}
			}
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					if(u==d[i][j]-s*i-t*j)ok[i][j]=true;
				}
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(!ok[i][j]){
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	printf("%d %d\n",202,200+101*101);
	for(int i=0;i<100;i++){
		printf("%d %d X\n",1+i,1+i+1);
		printf("%d %d Y\n",102+i+1,102+i);
	}
	for(int s=0;s<=100;s++){
		for(int t=0;t<=100;t++){
			int u=0;
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					chmax(u,d[i][j]-s*i-t*j);
				}
			}
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					if(u==d[i][j]-s*i-t*j)ok[i][j]=true;
				}
			}
			printf("%d %d %d\n",s+1,t+102,u);
		}
	}
	printf("%d %d\n",1,102);
}

