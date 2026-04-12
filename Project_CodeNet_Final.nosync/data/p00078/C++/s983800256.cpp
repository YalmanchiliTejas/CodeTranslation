#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	for(;;){
		int n,field[15][15] = {0};
		cin >>n;
		if(!n){break;}
		int x = n/2,y = n/2+1;
		field[x][y] = 1;
		for(int i=2; i<=n*n; i++){
			x++;
			y++;
			for(;;){
				if(x>=n){x = 0;}
				if(x<0){x = n-1;}
				if(y>=n){y = 0;}
				if(!field[x][y]){field[x][y] = i;break;}
				else if(field[x][y]){x--;y++;}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%4d",field[j][i]);
			}
			cout<<endl;
		}
	}
	return 0;
}