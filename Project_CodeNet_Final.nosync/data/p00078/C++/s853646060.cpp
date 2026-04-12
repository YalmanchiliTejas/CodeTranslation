#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	int n;
	while(cin>>n,n){
		int a[19][19]={0};
		int x=n/2+1;
		int y=n/2;
		
		a[x][y]=1;
		for(int i=2;i<=n*n;i++){
			x++;y++;
			if(n==x&&n==y){
				int k;
				//cout<<x<<" "<<y<<" "<<i<<endl;
				for(k=0;a[k][n-1]!=0;k++);
				x=k;y=n-1;
				//cout<<x<<" "<<y<<" "<<i<<endl;
				a[x][y]=i;continue;
			}
			if(a[x][y]!=0){
				x++;
				y--;			
			}
			//はみ出したら
			if(x>=n)x=0;
			if(y>=n)y=0;
			a[x][y]=i;
			//cout<<x<<" "<<y<<" "<<i<<endl;
		}
		
	//	a[0][n-1]=100;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%4d",a[i][j]);
			}
			cout<<endl;
		}
	}
	
}