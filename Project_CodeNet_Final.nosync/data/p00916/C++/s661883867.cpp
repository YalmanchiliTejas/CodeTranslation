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
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int y, int x, ll c, vector< vector<ll> > &area){
	if(area[y][x] != c) return;
	area[y][x] = 0;
	REP(i, 4){
		dfs(y+d[i][0], x+d[i][1], c, area);
	}
}

int n;
main(){
	while(cin >> n, n){
		set<int> x,y;
		vector<pii> p1, p2;
		REP(i, n){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			x.insert(a);
			y.insert(b);
			x.insert(c);
			y.insert(d);
			p1.push_back(pii(a, d));
			p2.push_back(pii(c, b));
		}
		map<int, int> xto, yto;
		int i=1;
		FOR(it, x) xto[*it] = ++i;
		i=1;
		FOR(it, y) yto[*it] = ++i;
		vector< vector<ll> > area(yto.size()+5, vector<ll>(xto.size()+5, 0));
		RREP(i, yto.size()+2){
			REP(j, xto.size()+2){
				area[i+1][j+1] = 1;
			}
		}
		REP(i, n){
//			printf("y:%d-%d x:%d-%d\n", yto[p1[i].second], yto[p2[i].second], xto[p1[i].first], xto[p2[i].first]);
			for(int j=yto[p1[i].second];j<yto[p2[i].second];j++)
				for(int k=xto[p1[i].first];k<xto[p2[i].first];k++)
					area[j][k] |= 1LL << (i+1);
		}
/*		RREP(i, yto.size()+4){
			REP(j, xto.size()+4){
				printf("%2llx ", area[i][j]);
			}
			cout << endl;
		}
*/		ll ans=0;
		REP(i, yto.size()+2){
			REP(j, xto.size()+2){
//				cout << i << " " << j << endl;
				if(area[i+1][j+1]){
					dfs(i+1, j+1, area[i+1][j+1], area);
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}