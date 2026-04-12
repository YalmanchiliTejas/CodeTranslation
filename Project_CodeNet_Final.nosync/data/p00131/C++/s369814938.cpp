#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int S3[1024];
	rep(S,1024){
		int stat=0;
		rep(j,10) if(S&(1<<j)) {
			stat^=1<<j;
			if(j>0) stat^=1<<(j-1);
			if(j<9) stat^=1<<(j+1);
		}
		S3[S]=stat;
	}

	int T; scanf("%d",&T);
	while(T--){
		int org[10]={};
		rep(i,10) rep(j,10) {
			int tmp; scanf("%d",&tmp);
			org[i]|=tmp<<j;
		}

		int ans=-1;
		rep(S,1024){
			int grid[10];
			rep(i,10) grid[i]=org[i];

			grid[0]^=S3[S];
			grid[1]^=S;
			for(int i=1;i<10;i++){
				int pttn=grid[i-1];
				grid[i-1]=0;
				grid[i]^=S3[pttn];
				if(i<9) grid[i+1]^=pttn;
			}

			if(grid[9]==0){ ans=S; break; }
		}
if(ans==-1)while(1);

		rep(j,10) printf("%d%c",!!(ans&(1<<j)),j<9?' ':'\n');
		org[0]^=S3[ans];
		org[1]^=ans;
		for(int i=1;i<10;i++){
			int pttn=org[i-1];
			org[i-1]=0;
			org[i]^=S3[pttn];
			if(i<10) org[i+1]^=pttn;
			rep(j,10) printf("%d%c",!!(pttn&(1<<j)),j<9?' ':'\n');
		}
	}

	return 0;
}