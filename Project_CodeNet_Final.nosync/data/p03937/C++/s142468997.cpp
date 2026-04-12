#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

string s[10];
bool used[10][10];
int h, w; 
void dfs(int y, int x){
	if(y + 1 < h && x < w && s[y + 1][x] == '#'){
		s[y + 1][x] = '.';
		used[y + 1][x] = true;
		dfs(y + 1, x);
	}else if(y < h && x + 1 < w && s[y][x + 1] == '#'){
		s[y][x + 1] = '.';
		used[y][x + 1] = true;
		dfs(y, x + 1);
	}
	return;
}

int main(void){
	cin >> h >> w;
	rep(i, h) cin >> s[i];
	rep(i, 10)rep(j, 10)used[i][j] = false;
	if(s[0][0] == '#'){
		used[0][0] = true;
		s[0][0] = '.';
		dfs(0, 0);
	}else{
		printf("Impossible\n");
	}

	rep(i, h)rep(j, w){
		if(s[i][j] == '#'){
			printf("Impossible\n");
			return 0;
		}
	}
	if(used[h - 1][w - 1]){
		printf("Possible\n");
	}else{
		printf("Impossible\n");
	}
	return 0;
}