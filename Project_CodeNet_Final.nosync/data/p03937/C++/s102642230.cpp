#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
const int N = 10;
const int inf = 1e5;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int h,w;
char s[N][N];

int solve(int row,int maxx){
	rep(j,1,w)
		if(s[row][j] == '#'){
			if(j < maxx) maxx = inf;
			else maxx = j;
		}
	return maxx;
}

int main()
{
	scanf("%d%d",&h,&w);
	rep(i,1,h) scanf("%s",s[i]+1);
	int maxx = 1;
	rep(i,1,h) maxx = solve(i,maxx);
	if(maxx == inf) printf("Impossible\n");
	else printf("Possible\n");
	return 0;
}