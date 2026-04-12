#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int board[16][16];
int n;//魔法陣n×n

void magic(int y,int x,int i){
	if(i >n*n)
		return ;
	if(y==n+1){//下にはみ出し
		magic(1,x,i);
		return;
	}
	if(x>n){//右にはみ出し
		magic(y,1,i);
		return ;
	}
	if(x<1){//左にはみ出し
		magic(y,n,i);
		return;
	}
	if(board[y][x]==0){
		board[y][x]=i;
		magic(y+1,x+1,i+1);
	}else{
		magic(y+1,x-1,i);
	}

}

int main(){
	while(cin>>n,n){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				board[i][j] = 0;
			}
		}
		int py =0.5*(n+3);
		int px =0.5*(n+1);
		board[py][px] = 1;
		magic(py+1,px+1,2);
		for(int i = 1;i <=n;i++){
			for(int j = 1;j <=n;j++){
				printf("%4d",board[i][j]);
			}
			cout <<endl;
		}
	}
	return 0;
}