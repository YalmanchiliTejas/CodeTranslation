#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>


#define reps(i,f,n) for(int i = f; i < int(n); i++)
#define rep(i,n) reps(i,0,n)

#define PII pair<int,int>
#define PP pair< int,PII >


using namespace std;

int c[16][16];

int main(){
	
	int n;
	while(scanf("%d", &n),n){
		int x = n/2;
		int y = n/2+1;
		rep(i,16)rep(j,16)c[i][j] = -1;
		
		reps(i,1,n*n+1){
			
			if(n <= x || x < 0 || n <= y){
				if(n <= x)x = 0;
				else if(x < 0)  x = n-1;
				else if(n <= y) y = 0;
				i--;
				continue;
			}
			
			if(c[y][x] != -1){
				x--;y++;
				i--;
				continue;
			}
			
			c[y][x] = i;
			x++;y++;
		}
		
		rep(i,n){
			rep(j,n){
				printf("%4d", c[i][j]);
			}puts("");
		}
	}
	
	return 0;
	
}