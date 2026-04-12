#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int c[10][10];
int visit[1<<16];
main(){
	cin >> n;
	vector<pii> stamp(n);
	REP(i, n){
		cin >> stamp[i].first >> stamp[i].second;
	}
	REP(i, 4)REP(j, 4){
		char ch;
		cin >> ch;
		if(ch == 'R') c[i][j] = 1;
		if(ch == 'G') c[i][j] = 2;
		if(ch == 'B') c[i][j] = 3;
	}
	queue<int> q;
	q.push(0);
	REP(i, 1<<16) visit[i] = 30;
	visit[0] = 0;
	while(!q.empty()){
		int b = q.front();q.pop();
		if(b == (1<<16)-1) break;
		REP(i, n){
			int h = stamp[i].first;
			int w = stamp[i].second;
			for(int sy=-h+1;sy<4;sy++)for(int sx=-w+1;sx<4;sx++){
				int col = -1;
				int bt = b;
				for(int y=sy;y<sy+h;y++)for(int x=sx;x<sx+w;x++){
					if(bt==-1||x<0||y<0||4<=x||4<=y) continue;
					if(!((b >> (4*y+x))&1)){
						bt |= 1<<(4*y+x);
						if(col == -1) col = c[y][x];
						else if(col != c[y][x]) bt = -1;
					}
				}
				if(bt >= 0 && visit[bt] > visit[b]+1){
					visit[bt] = visit[b]+1;
					q.push(bt);
				}
			}
		}
	}
	cout << visit[(1<<16)-1] << endl;
	return 0;
}