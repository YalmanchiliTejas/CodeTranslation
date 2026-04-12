#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a, i##_END_ = b; i < i##_END_; ++i)
#define per(i, a, b) for(int i = (b)-1, i##_BEGIN_ = a; i >= i##_BEGIN_; --i)
#define foreach(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#ifdef Leefir
	#define ast(x) assert(x)
	#define dig(...) fprintf(stderr, __VA_ARGS__)
#else
	#define ast(x) ;
	#define dig(...) ;
#endif
#define showtime dig("%.6lf\n", clock()/(double)CLOCKS_PER_SEC);
typedef long long ll;
typedef double db;
const int inf = (int)1e9;
const ll linf = (ll)1e18;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()

template<class TAT>
inline void read(TAT &res){
	char c; res = 0;
	bool neg = false;
	while(c = getchar(), c != '-' && (c < '0' || c > '9'));
	if(c == '-') neg = true, c = getchar();
	do res = (res*10) + (c^48);
	while(c = getchar(), c >= '0' && c <= '9');
	if(neg) res = -res;
}
template<class TAT>
inline void print(TAT x){
	if(x == 0){ putchar('0'); return;}
	if(x < 0){ putchar('-'); x = -x;}
	static char stk[30];
	int top = 0;
	while(x) stk[++top] = x%10^48, x /= 10;
	while(top) putchar(stk[top--]);
}
namespace Program{

const int N = (int)1e5;
//0 <= xi, yi <= 1e9
int n;
pii w[N+5];
int sx[N+5], sy[N+5];
bool cmpx(int x, int y){
	return w[x].x < w[y].x;
}
bool cmpy(int x, int y){
	return w[x].y < w[y].y;
}
int prex[N+5], nxtx[N+5];
int prey[N+5], nxty[N+5];
int posx[N+5], posy[N+5];
void input(){
	scanf("%d", &n);
	rep(i, 0, n) read(w[i].x), read(w[i].y);
	rep(i, 0, n) sx[i] = sy[i] = i;
	sort(sx, sx+n, cmpx); rep(i, 0, n) posx[sx[i]] = i;
	sort(sy, sy+n, cmpy); rep(i, 0, n) posy[sy[i]] = i;
	rep(i, 0, n) prex[i] = prey[i] = i-1, nxtx[i] = nxty[i] = i+1;
}
struct node{
	int id, cost;
	node(){}
	node(int _id, int _cost)
		: id(_id), cost(_cost){}
	bool operator <(const node &tmp)const{
		return cost > tmp.cost;
	}
};
priority_queue<node> que;
ll ans;
bool mark[N+5];
void delx(int p){
	if(nxtx[p]!=n) prex[nxtx[p]] = prex[p];
	if(prex[p]!=-1) nxtx[prex[p]] = nxtx[p];
}
void dely(int p){
	if(nxty[p]!=n) prey[nxty[p]] = prey[p];
	if(prey[p]!=-1) nxty[prey[p]] = nxty[p];
}
void del(int u){
	delx(posx[u]);
	dely(posy[u]);
}
void insx(int u, int v){
	que.push(node(v, abs(w[u].x-w[v].x)));
}
void insy(int u, int v){
	que.push(node(v, abs(w[u].y-w[v].y)));
}
void chk(int u){
	if(prex[posx[u]]!=-1) insx(u, sx[prex[posx[u]]]);
	if(nxtx[posx[u]]!=n) insx(u, sx[nxtx[posx[u]]]);
	if(prey[posy[u]]!=-1) insy(u, sy[prey[posy[u]]]);
	if(nxty[posy[u]]!=n) insy(u, sy[nxty[posy[u]]]);
	
	del(u);
}
void solve(){
	ans = 0;
	while(!que.empty()) que.pop();
	rep(i, 0, n) mark[i] = false;
	que.push(node(0, 0));
	while(!que.empty()){
		node now = que.top(); que.pop();
//		dig("%d %d\n", now.id, now.cost);
		int u = now.id;
		if(mark[u]) continue;
		mark[u] = true;
		ans += now.cost;
		chk(u);
	}
	cout << ans << endl;
}
void Main(){
	dig("______________________________D\n"); 
	input();
	solve();
}

} //namespace Program
/*
2s & 256M
There may be more than one town at the same coordinates.
long long
*/
int main(){
#ifdef Leefir
	dig("**********************define Leefir**********************\n");
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif
	srand(time(NULL));
	
	Program::Main();
	
	return 0;
}
