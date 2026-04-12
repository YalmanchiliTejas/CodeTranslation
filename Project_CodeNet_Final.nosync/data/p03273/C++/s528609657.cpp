#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

char map[100][100];

int main(){
	ios::sync_with_stdio(false);
	int h,w,flag;
	while(cin>>h>>w){
		int i,j;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				cin>>map[i][j];
			}
		}
		for(i=0;i<h;i++){
			flag=1;
			for(j=0;j<w;j++){
				if(map[i][j]=='#'){
					flag=0;
					break;
				}
			}
			if(flag){
				for(j=0;j<w;j++){
					map[i][j]='e';
				}
			}
		}
		for(i=0;i<w;i++){
			flag=1;
			for(j=0;j<h;j++){
				if(map[j][i]=='#'){
					flag=0;
					break;
				}
			}
			if(flag){
				for(j=0;j<h;j++){
					map[j][i]='e';
				}
			}
		}
		cout<<endl;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(map[i][j]!='e')
				cout<<map[i][j];					
			}
			for(j=0;j<w;j++){
				if(map[i][j]=='#'){
					cout<<endl;
					break;
				}
			}
		}
	}
	return 0;
}