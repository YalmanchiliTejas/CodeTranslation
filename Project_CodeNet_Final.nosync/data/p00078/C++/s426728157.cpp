#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int a[20][20];
int main(){
	int n;
	while(scanf("%d",&n),n){
		memset(a,0,sizeof(a));
		int px=n/2+1,py=n/2;
		rep(i,n*n){
			a[px][py]=i+1;
			px=(px+1)%n;
			py=(py+1)%n;
			if(a[px][py]){
				px=(px+1+n)%n;
				py=(py-1+n)%n;
			}
		}
		rep(i,n){
			rep(j,n){
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
	}
}