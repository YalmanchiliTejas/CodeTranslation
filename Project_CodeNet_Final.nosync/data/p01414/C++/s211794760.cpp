#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, h[16], w[16], col[3];
char in[4][5];
bool v[1 << 16];
int main(){
	cin >> n;
	rep(i, n) cin >> h[i] >> w[i];
	rep(i, 4){
		cin >> in[i];
		rep(j, 4) rep(k, 3){
			if(in[i][j] == "RGB"[k]) col[k] |= 1 << i * 4 + j;
		}
	}
	
	vi stamp;
	rep(i, n) for(int j = -h[i] + 1; j < 4; j++) for(int k = -w[i] + 1; k < 4; k++){
		int tx = min(max(0, j), 3), TX = min(max(0, j + h[i] - 1), 3);
		int ty = min(max(0, k), 3), TY = min(max(0, k + w[i] - 1), 3);
		
		int bit = 0;
		for(int l = tx; l <= TX; l++) for(int m = ty; m <= TY; m++)
		bit |= 1 << 4 * l + m;
		stamp.pb(bit);
	}
	sort(all(stamp));
	stamp.erase(unique(all(stamp)), stamp.end());
	int m = stamp.size();
	
	queue<pi> q;
	q.push(mp(0, 0));
	v[0] = 1;
	while(!q.empty()){
		int c = q.front().first, bit = q.front().second; q.pop();
		
		rep(i, stamp.size()) rep(j, 3){
			int nxt = bit & ~stamp[i] | stamp[i] & col[j];
			if(v[nxt]) continue;
			v[nxt] = 1;
			if(nxt == (1 << 16) - 1){
				cout << c + 1 << endl;
				return 0;
			}
			q.push(mp(c + 1, nxt));
		}
	}
	
	return 0;
}