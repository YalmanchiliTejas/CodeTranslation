#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		int x=n/2,y=n/2+1,fld[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fld[i][j]=-1;
			}
		}
		fld[x][y]=1;
		for(int i=2;i<=n*n;i++){
			x++;y++;
			while(1){				
				if(x<0)x=n-1;
				if(x>=n)x=0;
				if(y<0)y=n-1;
				if(y>=n)y=0;
				if(fld[x][y]==-1){
					fld[x][y]=i;
					break;
				}
				if(fld[x][y]!=-1){
					x--;y++;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%4d",fld[j][i]);
			}
			cout<<endl;
		}
	}		
}