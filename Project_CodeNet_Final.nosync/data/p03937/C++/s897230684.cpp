#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
////////////////////
int const N = 10;

string s[N];
int h, w;
int was[N][N];
int cn = 0;

void dfs(int y, int x){
	if(was[y][x]) return;
	was[y][x] = 1;
	if(x + 1 < w && s[y][x+1] == '#') dfs(y, x+1);
	if(y + 1 < h && s[y+1][x] == '#') dfs(y+1, x);
}

void solve(){
	cin >> h >> w;
	rep(i, 0, h) cin >> s[i];
	cn = h - 1 + w - 1 + 1;
	rep(i, 0, h) rep(j, 0, w) if(s[i][j] == '#') --cn;
	dfs(0, 0);
	
	
	if(cn == 0 && was[h-1][w-1]) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();

	return 0;
}