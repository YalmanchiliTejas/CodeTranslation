#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int INF = 1e9;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	VI d(n, -1);
	REP(i,m){
		int x;
		cin >> x;
		d[x-1] = i;
	}
	VVI e(m, VI(k));
	REP(i,n) REP(j,k){
		int x;
		cin >> x;
		if (d[i] == -1) continue;
		e[d[i]][j] = d[x-1];
	}

	VI dist(1<<m, INF);
	dist[(1<<m)-1] = 0;
	queue<int> que;
	que.push((1<<m)-1);
	while (dist[0] == INF){
		int a = que.front();
		que.pop();
		REP(j,k){
			int x = 0;
			REP(i,m){
				if ((a>>i) & 1 && e[i][j] >= 0){
					x |= (1<<e[i][j]);
				}
			}
			if (dist[x] != INF) continue;
			dist[x] = dist[a] + 1;
			que.push(x);
		}
	}

	cout << dist[0] << endl;

    return 0;
}