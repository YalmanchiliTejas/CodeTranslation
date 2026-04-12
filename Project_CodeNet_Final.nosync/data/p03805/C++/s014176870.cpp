//http://abc054.contest.atcoder.jp/tasks/abc054_c
//https://book.mynavi.jp/manatee/detail/id=65960
#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
typedef long long ll;
using namespace std;
const int INF=1e9, MOD=1e9+7;
const int MAX_N=10000;
int n,m,a,b;

bool con[8][8]={}; //con[i][j]:=iとjがつながっているか。
bool stay[8]={}; //既に訪問したか。

int dfs(int now,int d){ //今いる頂点(now), 深度(d)
	if(stay[now]) return 0;
	if(d==n) return 1;
	
	stay[now]=true;
	
	int c=0;
	REP(i,0,n) if(con[now][i]) c+=dfs(i,d+1);
	
	stay[now]=false;
	
	return c;
}
	
int main(){
	cin >> n >> m;
	REP(i,0,m){
		cin >> a >> b;
		con[a-1][b-1]=con[b-1][a-1]=true;
	}
	
	cout << dfs(0,1) << endl;
	return 0;
}
