#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 999999
#define rep(i,j) for(int i=0;i<(j);++i)
#define reps(i,j,k) for(int i=j;i<k;++i)
typedef long long ll;
typedef unsigned long long ull;
int stage[20][20];
int main(){
	int n;
	while(scanf("%d",&n),n){
		memset(stage,0,sizeof(stage));
		int x= n/2;
		int y = x+1;
		int cnt = 1;
		while(n*n >= cnt){
			if(x < 0){
				x = n-1;
			}
			else if(n <= x){
				x = 0;
			}
			else if(n <= y){
				y = 0;
			}
			else if(stage[y][x]){
				x--;
				y++;
			}
			else{
				stage[y][x] = cnt++;
				x++;
				y++;
			}
		}
		rep(i,n){
			rep(j,n){
				printf("%4d",stage[i][j]);
			}
			puts("");
		}
	}
	return 0;
}