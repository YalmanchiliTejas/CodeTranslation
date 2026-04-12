#include<cstdio>
#include<iostream>

#define NMAX 15

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);

	int n;
	int magic[NMAX+1][NMAX+1];
	int cnt;
	int x,y;

	while(1){
		cin>>n;
		if(n==0) break;
		for(int i=0;i<NMAX+1;i++){
			for(int j=0;j<NMAX+1;j++){
				magic[i][j]=0;
			}
		}
		cnt=0;
		x=(n/2)+1;
		y=(n/2)+2;
		while(cnt!=n*n){
			if(magic[y][x]==0){
				magic[y][x]=cnt+1;
				x+=1;
				y+=1;
				cnt++;
			}
			else{
				x-=1;
				y+=1;
			}
			if(x<=0) x=n;
			else if(x>n) x=1;
			if(y<=0) y=n;
			else if(y>n) y=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%4d",magic[i][j]);
			}
			printf("\n");
		}
	}
		
	return 0;
}