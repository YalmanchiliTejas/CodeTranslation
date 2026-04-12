#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long int ll;


using namespace std;

string s;

int main(){
	int n;
	while(1){
		cin>>n;
		if(n==0)break;
		vector<vector<int> > v(n,vector<int> (n,0));
		int x=n/2,y=n-x;
		for(int i=1; i<=n*n; i++){
			while(1){
				if(x>=0&&y>=0&&x<n&&y<n&&v[x][y]==0){
					v[x][y]=i;
					x++;
					y++;
					break;
				}
				if(x>=n)x=0;
				if(x<0)x=n-1;
				if(y>=n)y=0;
				if(v[x][y]>0){
					x--;
					y++;
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%4d",v[j][i]);
			}
			printf("\n");
		}
	}
}