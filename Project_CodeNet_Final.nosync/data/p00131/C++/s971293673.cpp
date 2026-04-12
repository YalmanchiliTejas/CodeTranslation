#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <complex>
using namespace std;

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define EPS 1e-8
#define DEB 1

const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
int field[16][16],tmp[16][16];
vector<pair<int,int> > v;

void touch(int x, int y){
	tmp[y][x] ^= 1;
	rep(k,4){
		int tx = x + dx[k];
		int ty = y + dy[k];
		if( tx<0 || ty<0 || tx>=10 || ty>=10 )continue;
		tmp[ty][tx] ^= 1;
	}
}
bool ok(){
	rep(i,10)rep(j,10)if( tmp[i][j]==1 ) return false;
	return true;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		rep(i,10)rep(j,10)scanf("%d",&field[i][j]);

		rep(i,1<<10){
			v.clear();
			rep(j,10)rep(k,10)tmp[j][k]=field[j][k];
			
			rep(j,10)if( (1<<j)&i ){
				touch(j,0);
				v.push_back(mp(j,0));
			}
			REP(k,1,10){
				rep(j,10){
					if( tmp[k-1][j]==1 ){
						touch(j,k);
						v.push_back(mp(j,k));
					}
				}
			}
			if( ok() ){
				break;
			}
		}
		int ans[10][10];
		memset(ans,0,sizeof(ans));
		rep(i,v.size())ans[v[i].second][v[i].first] = 1;
		rep(i,10){
			rep(j,10){
				if( j>0 )putchar(' ');
				printf("%d",ans[i][j]);
			}
			puts("");
		}
		   
	}
	
	return 0;
}