#include<iostream>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;

int main(){
	int n;
	while(cin>>n,n){
		int matrix[n][n];
		rep(i,n)rep(j,n)matrix[i][j]=0;
		matrix[n/2+1][n/2]=1;
		int nx=n/2,ny=n/2+1;
		int counta=2;
		while(1){
			nx++;
			ny++;
			if(nx==n)nx=0;
			if(ny==n)ny=0;
			if(matrix[ny][nx]!=0){
				nx--;
				ny++;
				if(nx==-1)nx=n-1;
				if(ny==n)ny=0;
			}
			matrix[ny][nx]=counta;
			counta++;
			if(counta>n*n)break;
		}
		rep(i,n){
			rep(j,n){
				if(matrix[i][j]/100>0){
					cout<<" "<<matrix[i][j];
				}else if(matrix[i][j]/10>0){
					cout<<"  "<<matrix[i][j];
				}else{
					cout<<"   "<<matrix[i][j];
				}
			}
			cout<<endl;
		}
	}
}