//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
char c[9][9];
int OK=0;int h,w;
void Dfs(int x,int y){
	if(x==h&&y==w) {
		OK=1;
		return;
	}
	if(x+1<=h&&c[x+1][y]=='#'){
		c[x+1][y]='.';
		Dfs(x+1,y);
	}
	else{
		if(y+1<=w&&c[x][y+1]=='#'){
			c[x][y+1]='.';
			Dfs(x,y+1); 
		}
		else return;
	}
}
int main(){
	cin>>h>>w;
	rb(i,1,h)
		rb(j,1,w) cin>>c[i][j];
	if(c[1][1]!='#'||c[h][w]!='#'){
		puts("Impossible");
		return 0;
	}
	c[1][1]='.';
	Dfs(1,1);
	rb(i,1,h)
		rb(j,1,w){
			if(c[i][j]=='#'){
				puts("Impossible");
		return 0;
			}
		}
	if(OK) puts("Possible");
	else puts("Impossible");
	return 0;
}
