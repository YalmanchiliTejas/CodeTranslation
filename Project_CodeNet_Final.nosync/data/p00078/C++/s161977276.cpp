#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	int n;
	int field[16][16];
	while(cin>>n&&n!=0){
		memset(field,0,sizeof(field));
		field[(n/2)+1][n/2]=1;
		int cx=n/2;
		int cy=(n/2)+1;
		int num=2;
		int sw=0;
		while(1){
			if(sw==0){
				int ny=(cy+1)%n;
				int nx=(cx+1)%n;
				if(field[ny][nx]==0){
					field[ny][nx]=num;
					if(num==n*n)
						break;
					num++;
					cx=nx,cy=ny;
				}
				else{
					sw=1;
					cx=nx,cy=ny;
				}
			}
			else{
				int ny=(cy+1)%n;
				int nx=(cx+n-1)%n;
				if(field[ny][nx]==0){
					field[ny][nx]=num;
					if(num==n*n)
						break;
					num++;
					sw=0;
					cx=nx,cy=ny;
				}
				else{
					sw=1;
					cx=nx,cy=ny;
				}
			}

		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%4d",field[i][j]);
			}
			cout<<endl;
		}
	}

	return 0;
}