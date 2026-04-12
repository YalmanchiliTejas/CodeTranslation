#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
#define ANS(n) cout << (n) << endl

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>=(b);i--)

#define ALL(obj) (obj).begin(),(obj).end()

#define pii pair<int,int>

#define pb(a) push_back(a)
#define mp make_pair

int main()
{
	int h,w;
	cin >> h >> w;
	char a[h][w];
	FOR(i,0,h)FOR(j,0,w)cin >> a[i][j];
	int cy,cx;
	cy = cx = 0;
	bool ans = true;
	while(cy != h-1 || cx != w-1){
		a[cy][cx] = '.';
		char sita = (cy < h-1)?a[cy+1][cx]:'.';
		char migi = (cx < w-1)?a[cy][cx+1]:'.';
		if(sita == '#' && migi == '#'){
			ans = false;
			break;
		}else if(sita == '.' && migi == '.'){
			ans = false;
			break;
		}else{
			if(sita == '#'){
				cy++;
			}else{
				cx++;
			}
		}
	}
	a[h-1][w-1] = '.';
	FOR(i,0,h)FOR(j,0,w){
		if(a[i][j] == '#'){
			ans = false;
			break;
		}
	}
	Possible(ans);
	return 0;
}
