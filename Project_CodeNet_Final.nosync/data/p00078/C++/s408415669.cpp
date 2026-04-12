#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

//AOJ0078
#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;


int main(void){

int n,y,x;

	while(cin >> n){
		if(n==0 || cin.eof()) break;
		vector<vector<int> > ms(n,vector<int>(n,-1));
		y=n/2+1; x=n/2;
		ms[y][x]=1; 
		int zz=2;
		x++; y++;
		while(zz<=n*n){
		  	
			if(x>=n ) x=0;
			if(x<0 ) x=n-1;
			if(y>=n ) y=0;
			if( ms[y][x]>0) {x--; y++;}
			if( x>=0 && x<n && y<n && y>=0 && ms[y][x]<1  ){
				ms[y][x]=zz; zz++;
				x++; y++;
			}
			
			
		}
		rep(i,n){
			rep(j,n) printf("%4d",ms[i][j]);
			printf("\n");
		}
		
	}
	
	return 0;
	
}