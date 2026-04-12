#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)
#define fst first
#define snd second
#define Pqaz(T) priority_queue<T,vector<T>,greater<T>>
#define Pqza(T) priority_queue<T>
#define ENJYU std::ios::sync_with_stdio(false);std::cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> llP;
typedef pair<int, int> intP;

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int N, M;

int dx[]={1,0};
int dy[]={0,1};
char maze[10][10];

void dfs(int x, int y) {
	maze[y][x] = '.';
	rep(2, i) {
		if (maze[y+dy[i]][x+dx[i]] == '#' && x < M && y < N) {
			dfs(x+dx[i], y+dy[i]);
			break;
		}
	}
}

void solve(void){

	cin >> N >> M;
	rep(N, i) rep(M, j) cin >> maze[i][j];
	dfs(0, 0);
	rep(N, i) rep(M, j) {
		if (maze[i][j] == '#') {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << "Possible" << endl;

}

int main(void){
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
