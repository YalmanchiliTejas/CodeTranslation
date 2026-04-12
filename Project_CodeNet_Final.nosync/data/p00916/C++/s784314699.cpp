#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

int n;
ll field[110][110];
int l[50],t[50],r[50],b[50];

int di[4]={1,0,-1,0};
int dj[4]={0,1,0,-1};
bool visited[110][110];

void dfs(int ci,int cj){
	if(visited[ci][cj]) return;
	visited[ci][cj]=true;
	rep(i,4){
		int ni=ci+di[i];
		int nj=cj+dj[i];
		if(ni<0||110<=ni||nj<0||110<=nj) continue;
		if(field[ni][nj]==field[ci][cj]) dfs(ni,nj);
	}
	return ;
}

int main(void){
	while(cin >> n,n){
		clr(field,0);
		clr(visited,false);
		rep(i,n) cin >> l[i] >> t[i] >> r[i] >> b[i];
		int x[110],y[110];
		rep(i,n) x[2*i]=l[i],x[2*i+1]=r[i],y[2*i]=t[i],y[2*i+1]=b[i];
		sort(x,x+2*n);
		sort(y,y+2*n);
		int xnum=unique(x,x+2*n)-x;
		int ynum=unique(y,y+2*n)-y;
		rep(i,n){
			int lindex=lower_bound(x,x+xnum,l[i])-x;
			int rindex=lower_bound(x,x+xnum,r[i])-x;
			int tindex=lower_bound(y,y+ynum,t[i])-y;
			int bindex=lower_bound(y,y+ynum,b[i])-y;
			field[lindex][bindex]+=(1LL<<i);
			field[rindex][bindex]-=(1LL<<i);
			field[lindex][tindex]-=(1LL<<i);
			field[rindex][tindex]+=(1LL<<i);
		}
		rep(i,105) rep(j,105) field[i][j+1]+=field[i][j];
		rep(i,105) rep(j,105) field[i+1][j]+=field[i][j];

		ll ans=1LL;
		rep(i,105) if(field[i][0]==0&&!visited[i][0]) dfs(i,0);
		rep(i,105) if(field[0][i]==0&&!visited[0][i]) dfs(0,i);
		rep(i,105) if(field[i][105]==0&&!visited[i][105]) dfs(i,105);
		rep(i,105) if(field[105][i]==0&&!visited[105][i]) dfs(105,i);

		rep(i,105)rep(j,105) if(!visited[i][j]) ans++,dfs(i,j);
		cout << ans << endl;
	}
	return 0;
}