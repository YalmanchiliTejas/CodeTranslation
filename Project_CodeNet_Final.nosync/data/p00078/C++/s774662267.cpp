#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;


bool check(int a[15][15],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0)return true;
		}
	}
	return false;
}
int main(){
	int n;
	int data[15][15];
	while(cin >> n , n ){
		memset(data,0,15*15*4);
		int x = n/2;
		int y = n/2+1;
		data[x][y] = 1;
		int cnt=2;
		while(check(data,n)){
			int nx,ny;
			nx = (x+n+1)%n;
			ny = (y+1)%n;
			if(data[nx][ny]!=0){
				do{
					nx = (nx+n-1)%n;
					ny = (ny+1)%n;
				}while(data[nx][ny]!=0);
				data[nx][ny]=cnt++;
			}else{
				data[nx][ny]=cnt++;
			}
			x = nx;
			y = ny;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%4d",data[j][i]);
			}
			puts("");
		}
	}
}