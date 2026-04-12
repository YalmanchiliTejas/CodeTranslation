#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

ll H, W;
ll input[10][10];
ll visited[10][10];

void dfs(ll x, ll y, ll dist){
	if(input[x][y]==0) return;
	visited[x][y] = max(visited[x][y], dist);
	if(x+1<H) dfs(x+1, y, visited[x][y]+1);
	if(y+1<W) dfs(x, y+1, visited[x][y]+1);
	return;
}

int main(){
	cin >> H >> W;
	string S;
	ll sum = 0;
	REP(i, H){
		cin >> S;
		REP(j, W){
			input[i][j] = (S[j]=='#'?1:0);
			if(S[j]=='#') sum++;
		}
	}

	REP(i, H)REP(j, W) visited[i][j] = -1;
	dfs(0, 0, 0);

	/*
	REP(i, H){
		REP(j, W){
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	*/

	cout << (visited[H-1][W-1]==sum-1?"Possible":"Impossible") << endl;
    return 0;
}