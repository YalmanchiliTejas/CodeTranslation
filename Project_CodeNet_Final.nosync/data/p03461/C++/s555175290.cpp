#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,ll> PPI;
typedef pair<ll,P> PIP;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vp;
#define PQ(T) priority_queue<T,vector<T>,greater<T>>
#define PQ2(T) priority_queue<T>
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define REP(i,a,b) for(ll (i)=a;(i)<(ll)(b);++(i))
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(x,y) ((x)=min((x),(y)))
#define chmax(x,y) ((x)=max((x),(y)))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
#define DEBUG(x) cerr<<"line ("<<__LINE__<<")  "<<#x<<": "<<x<<endl;
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 20
#define M 221
ll d[N][N];
ll g[M+10][M+10];
ll gg[M][M];

int main(){
	ll a, b;
	cin>>a>>b;
	rep1(i, a) rep1(j, b) cin>>d[i][j];
	mset(g, -1);
	bool ng = false;
	rep1(i, a-1) rep1(j, b-1){
		if(d[i+1][j]-d[i][j]<0) ng = true;
		if(d[i][j+1]-d[i][j]<0) ng = true;
		if(i+2<=a&&(d[i+1][j]-d[i][j]<d[i+2][j]-d[i+1][j])) ng = true;
		if(j+2<=b&&(d[i][j+1]-d[i][j]<d[i][j+2]-d[i][j+1])) ng = true;
	}
	if(ng){
		cout<<"Impossible"<<endl;
		return 0;
	}
	ll m = 200+100*100-1;
	rep(i, 100) rep(j, 100){
		if(i==99&&j==99) break;
		ll c = 0;
		rep1(i2, a) rep1(j2, b) chmax(c, d[i2][j2]-(i*i2+j*j2));
		g[1+i][201-j] = c;
	}
	/*for(ll i = a; i >= 1; i--){
		for(ll j = b; j >= 1; j--){
			ll x = 0, y = 0;
			for(int k = i+1; k <= a; k++) chmax(x, (d[k][j]-d[i][j]+k-i-1)/(k-i));
			for(int k = j+1; k <= b; k++) chmax(y, (d[i][k]-d[i][j]+k-j-1)/(k-j));
			//ll x = i<a?(d[a][j]-d[i][j]+a-i)/(a-i):0;
			//ll y = j<b?(d[i][b]-d[i][j]+b-j)/(b-j):0;
			ll c = d[i][j]-x*i-y*j;
			//cerr<<i<<" "<<j<<endl;
			//cerr<<x<<" "<<y<<" "<<c<<endl;
			if(x<0||y<0||(g[x+1][201-y]!=-1)||(c<0||c>100)){
				cout<<"Impossible"<<endl;
				return 0;
			}
			if(g[x+1][201-y]==-1) m++;
			chmax(g[x+1][201-y], c);
			//cerr<<x<<" "<<y<<" "<<c<<endl;
		}
	}*/
	rep1(i, a) rep1(j, b){
		rep(i2, M) fill(gg[i2], gg[i2]+M, INF);
		rep(i2, M) gg[i2][i2] = 0;
		REP(i2, 1, 101) gg[i2][i2+1] = i;
		REP(i2, 101, 201) gg[i2][i2+1] = j;
		rep(i2, M) rep(j2, M) if(g[i2][j2]!=-1) gg[i2][j2] = g[i2][j2];
		rep(k, M) rep(i2, M) rep(j2, M) chmin(gg[i2][j2], gg[i2][k]+gg[k][j2]);
		if(gg[1][201]!=d[i][j]){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	cout<<"Possible"<<endl;
	cout<<201<<" "<<m<<endl;
	for(ll i = 1; i <= 100; i++) cout<<i<<" "<<i+1<<" X"<<endl;
	for(ll i = 101; i <= 200; i++) cout<<i<<" "<<i+1<<" Y"<<endl;
	rep(i, M) rep(j, M) if(g[i][j]!=-1) cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
	cout<<"1 201"<<endl;
	return 0;
}
