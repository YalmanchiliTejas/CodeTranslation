#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[15][15];
int main(){
	int n;
	while(cin>>n&&n){
		memset(a,0,sizeof(a));
		int y=n/2+1,x=n/2;
		int cur=1;
		while(cur<=n*n){
			if(a[y][x]==0){
				a[y][x]=cur++;
				y++;x++;
			}else{
				y++;x--;
			}	
			if(x<0)x=n-1;
			else if(n<=x)x=0;
			if(n<=y)y=0;
		}
		for(y=0;y<n;y++){
			for(x=0;x<n;x++){
				printf(" %3d",a[y][x]);
			}
			puts("");
		}
	}
	return 0;
}