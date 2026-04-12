#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include <bitset>

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <fstream>
#include <random>
//#include <time.h>
#include <ctime>
#pragma endregion //#include
/////////
#define REP(i, x, n) for(int i = x; i < n; ++i)
#define rep(i,n) REP(i,0,n)
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;
/////////
#pragma region Math
#pragma region
template<class T>
inline T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
#pragma endregion // 最大公約数 gcd
#pragma region
template<class T>
inline T lcm(T a, T b){return a / gcd(a, b) * b;}
#pragma endregion // 最小公倍数 lcm
#pragma region
LL powMod(LL num,LL n,LL mod=(LL)MOD){//(num**n)%mod
	num %= mod;//
	if( n == 0 ){
		return (LL)1;
	}
	LL mul = num;
	LL ans = (LL)1;
	while(n){
		if( n&1 ){
			ans = (ans*mul)%mod;
		}
		mul = (mul*mul)%mod;
		n >>= 1;
	}
	return ans;
}
LL mod_inverse(LL num,LL mod=MOD){
	return powMod(num,MOD-2,MOD);
}
#pragma endregion //繰り返し二乗法 powMod
#pragma region
template<class T>
vector<T> getDivisor(T n){
	vector<T> v;
	for(int i=1;i*i<=n;++i){
		if( n%i == 0 ){
			v.push_back(i);
			if( i != n/i ){//平方数で重複して数えないように
				v.push_back(n/i);
			}
		}
	}
	sort(v.begin(), v.end());
	return v;
}
#pragma endregion //約数列挙 getDivisor(n):O(√n)
#pragma endregion //math
//Utility:便利な奴
#pragma region
template<class T>
void UNIQUE(vector<T>& vec){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end() );
}
#pragma endregion // sort erase unique
////////////////////////////////
#pragma region 
long long  bitcount64(long long bits)
{
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >>16 & 0x0000ffff0000ffff);
    return (bits & 0x00000000ffffffff) + (bits >>32 & 0x00000000ffffffff);
}
#pragma endregion //その他
////////////////////////////////
struct edge_base{int to;LL cost;};
edge_base make_edge_base(int to,LL cost){
	edge_base ret = {to,cost};
	return ret;
}
#pragma region GRL
#pragma region //グラフ
template<class T,class EDGE>
void dijkstra(int root,int V,vector<T>& dist,
	vector< vector<EDGE> > G	){
	priority_queue<pair<T,int>,vector<pair<T,int> >,greater<pair<T,int> > > que;
	dist.assign(V,LINF);
	dist[root] = 0;
	que.push(pair<T,int>(0,root));//距離、頂点番号

	while( !que.empty() ){
		pair<T,int> p = que.top();que.pop();
		int v = p.second;
		if( dist[v] < p.first ) continue;
		for(int i=0;i < (int)G[v].size();++i){
			EDGE e = G[v][i];
			if( dist[e.to] > dist[v] + e.cost ){
				dist[e.to] = dist[v] + e.cost;
				que.push(pair<T,int>(dist[e.to],e.to));
			}
		}
	}
}
#pragma endregion //ダイクストラ法:O(|E|log|V|)
#pragma region //グラフ
void warshall_floyd(vector<vector<LL> >& dist,int V,const LL inf=LINF){
	for(int k=0;k<V;++k){
		for(int i=0;i<V;++i){
			if( dist[i][k] >= inf ) continue;
			for(int j=0;j<V;++j){
				if( dist[k][j] >= inf )continue;
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
#pragma endregion //ワーシャルフロイド:O(|V|**3)
#pragma region
namespace FLOW{
//vector< vector<FLOW:edge> > G;

struct edge_flow : public edge_base{
	int cap;//LD cap;//
	int rev;
};
edge_flow make_edge_flow(int to,int cap,int rev,LL cost=1){
//edge_flow make_edge_flow(int to,LD cap,int rev,LL cost=1){
	edge_flow ret;
	
	ret.to = to;
	ret.cost = cost;
	ret.cap = cap;
	ret.rev = rev;
	return ret;
}

//*
class Graph{
public:
	int V;
	vector< vector<FLOW::edge_flow> > G;
	vector< LL > dist;
	vector< int > iter;
	void init(int v){
		V = v;
		G.resize(V);
	}
	//directed graph
	void add_edge(int from,int to,int cap){
		G[from].push_back( FLOW::make_edge_flow(to,cap,G[to].size()) );
		G[to].push_back( FLOW::make_edge_flow(from,0,G[from].size()-1) );
	}
	
private:
	//sから最短距離をBFSで計算する
	void bfs(int s){//許容量もチェックしている
		queue<int> que;
		dist = vector<LL>(V,-1);
		dist[s] = 0;
		que.push(s);
		while(!que.empty()){
			int v = que.front();que.pop();
			for(int i=0;i<(int)G[v].size();++i){
				edge_flow &e = G[v][i];
				if( e.cap > 0 && dist[e.to] < 0 ){
					dist[e.to] = dist[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
private:
	//増加パスをDFSで探す
	int dfs(int v,int t,int f){
		if( v==t ) return f;
		for(int &i = iter[v];i<(int)G[v].size();++i){//?
			FLOW::edge_flow &e = G[v][i];
			if( e.cap>0 && dist[v] < dist[e.to]){
				int d = this->dfs(e.to, t, min(f,e.cap) );
				if( d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
public:
	//sからtへの最大流量を求める
	int max_flow(int s,int t){
		int flow = 0;
		for(;;){
			this->bfs(s);
			if( dist[t] < 0 ) return flow;
			iter = vector<int>(V,0);
			int f;
			while( (f = this->dfs(s,t,INF) ) > 0 ){
				flow += f;
			}
		}
	}
};
//*/
}
#pragma endregion //dinic :O(|E||V|^2)
#pragma region //グラフ
bool is_bipartite(int v,int c,vector< vector<int> >& G,vector<int>& Color){
	Color[v] = c;
	for(int i=0;i < (int)G[v].size();++i){//隣接グラフ
		if(Color[ G[v][i] ] == c ) return false;
		if(Color[ G[v][i] ] == 0 && 
			!is_bipartite(G[v][i],-c,G,Color)
			){
				return false;
		}
	}
	return true;
}
bool is_bipartite(int Root,vector< vector<int> >& Graph){
	int GraphSize = Graph.size();
	vector<int> Color(GraphSize,0);
	const int ColorNo = 1;
	return is_bipartite(Root,ColorNo,Graph,Color);
}
#pragma endregion //二部グラフチェック is_bipartite(root,GraphList)
#pragma endregion //
#pragma region 
vector< vector<LL> > NCK;//初期値:0
//http://sugarknri.hatenablog.com/entry/2016/07/16/165715
void makeinv(vector<LL>& inv,const LL P){
	int i;
	//const int varMAX = max(100000,(int)inv.size());
	const int varMAX = max(100010,(int)inv.size());
	
	inv = vector<LL>( varMAX+1,0);
	inv[1]=1;
	for(i=2;i<=varMAX;i++){
		inv[i] = (inv[P%i] * (P-P/i)%P ) % P;//OVF
		//inv[i] = powMod(i,P-2,P);
	}
}

LL nCk(LL N,LL k,LL mod = MOD){
	static vector<LL> inv;//modの逆元
	if( inv.size() == 0 ){
		makeinv(inv,mod);//modは素数を入れる
	}
	k = min(k,N-k);
	if( k < 0 || k > N){return 0;}
	if( k == 0 ){return 1;}
	if( k == 1 ){return N%mod;}
	LL ret = 1;
	for(int i=1;i<=k;++i){
		ret = (ret * ((N+1-i)%mod) )%mod;//ret*N:OVF
		ret = (ret * inv[i] )%mod;
	}
	return ret;
}
LL nCk_once(LL N,LL k,LL mod = MOD){//modは素数
	k = min(k,N-k);
	if( k < 0 || k > N ){return 0;}
	if( k == 0 ){return 1;}
	if( k == 1 ){return N%mod;}
	LL ret = 1;
	LL A=1;
	for(LL i=0;i<k;++i){
		A = (A * ((N-i)%mod) ) % mod;
	}
	LL B=1;
	for(LL i=2;i<=k;++i){
		B = (B * (i%mod) ) % mod;
	}
	ret = ( A * powMod(B,mod-2,mod) ) % mod;
	return ret;
}
#pragma endregion //組み合わせnCk(,10^5)
#pragma region

LL nCk_base(int N,int K,LL mod=MOD){
	if( K<0 || N < K ) return 0;//多く取り過ぎ
	K = min(K,N-K);
	if( K==0 ){return 1%mod;}
	if( K==1 ){return N%mod;}//%MOD;
	if( N<=10000 && NCK[N][K] ){
		return NCK[N][K];
	}
	//N個目を使わない:nCk(N-1,k)
	//N個目を使う	:nCk(N-1,k-1)
	LL ans = (nCk_base(N-1,K)+nCk_base(N-1,K-1) )%mod;//%MOD;
	if( N<=10000 ){
		NCK[N][K] = ans;
	}
	return ans;
}

#pragma endregion //組み合わせ メモ?
#pragma region CGL
class Point{
public:
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}

	Point	operator +	(Point p){return Point(add(x,p.x),add(y,p.y));}
	void	operator +=	(Point p){x=add(x,p.x);y=add(y,p.y);}
	Point	operator -	(Point p){return Point(add(x,-p.x),add(y,-p.y));}
	void	operator -=	(Point p){x=add(x,-p.x);y=add(y,-p.y);}
	Point	operator *	(double a){return Point(x*a,y*a);}
	double	operator *	(Point p){return dot(p);}
	Point	operator /	(double a){return Point(x/a,y/a);}

	double norm(){return sqrt(x*x+y*y);}
	double dot(Point p){return add(x*p.x,y*p.y);}
	double rot(Point p){return add(x*p.y,-y*p.x);}
	double add(double a,double b){
		double EPS = 1e-10;
		if( abs(a+b) < EPS*(abs(a)+abs(b)) ){
			return 0;
		}
		return a+b;
	}
};
istream& operator>>(istream& in,Point& P){
	in >> P.x >> P.y;
	return in;
}
bool operator==(Point A,Point B){
	if( A.x==B.x && A.y==B.y)return true;
	return false;
}
bool operator<(Point A,Point B){
	if( A.x < B.x ) return true;
	else if( A.x > B.x ) return false;
	if( A.y < B.y ) return true;
	return false;
}
bool operator>(Point A,Point B){
	if( A<B ) return false;
	if( A==B ) return false;
	return true;
}

//線分で表した直線の交差判定
bool is_cross(Point p1,Point p2,Point q1,Point q2){
	double res = (p2-p1).rot(q2-q1);
	return  res != 0;//平行なら0
}

/*ccwへ//線分p1-p2上に点qがあるか判定
bool on_seg(Point p1,Point p2,Point q){
	return (p1-q).rot(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}*/
//直線p1-p2と直線q1-q2の交点
//交差判定をしてから使う:0除算
Point intersection(Point p1,Point p2,Point q1,Point q2){
	return p1+(p2-p1)*((q2-q1).rot(q1-p1)/(q2-q1).rot(p2-p1));
}

//線分ABに対する点C
enum PointPotion{ONLINE_BACK=-2,CLOCKWISE,ON_SEGMENT,COUNTER_CLOCKWISE,ONLINE_FRONT};
PointPotion ccw(Point A,Point B,Point C){
	B -= A;C -=A;
	if( B.rot(C) > 0 ) return COUNTER_CLOCKWISE;//+1
	if( B.rot(C) < 0 ) return CLOCKWISE;//-1
	if( B.dot(C) < 0 ) return ONLINE_BACK;//-2
	if( B.norm() < C.norm() ) return ONLINE_FRONT;//+2
	return ON_SEGMENT;//0
}
//線分p1-p2,と線分q1-q2の交差判定
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool intersect(Point p1,Point p2,Point q1,Point q2){
	return	(ccw(p1,p2,q1) * ccw(p1,p2,q2) <= 0) &&
			(ccw(q1,q2,p1) * ccw(q1,q2,p2) <= 0);
}
///
//直線p1-p2と点q1の距離
double dist_LineP(Point p1,Point p2,Point q1){
	return abs( (p2-p1).rot(q1-p1) )/(p2-p1).norm();
}
//線分p1-p2と点q1の距離
double dist_SegP(Point p1,Point p2,Point q1){
	//(日)
	if( (p2-p1).dot(q1-p1) < 0 ){
		return (q1-p1).norm();//p1から見てp2と逆方向
	}
	if( (p1-p2).dot(q1-p2) < 0 ){
		return (q1-p2).norm();//p2から見てp1と逆方向
	}
	return dist_LineP(p1,p2,q1);//垂線下ろす
}
// 線分同士の最短距離
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=862507#1
double dist_segseg(Point A1,Point A2,Point B1,Point B2){
	if( intersect(A1,A2,B1,B2) ){
		return 0;
	}
	return min(
		min(dist_SegP(A1,A2,B1),
			dist_SegP(A1,A2,B2)
			),
		min(dist_SegP(B1,B2,A1),
			dist_SegP(B1,B2,A2)
			)
		);
}
#pragma endregion //class Point
#pragma region CGL
//多角形内なら2,線上なら1,外なら0
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
//http://www.prefield.com/algorithm/geometry/contains.html
//点Pから半直線を引く、ガウス
int contains(vector<Point>& v,Point& P){
	bool in = false;
	const int N = v.size();
	for(int i=0;i<N;++i){
		Point A = (v[i]-P);
		Point B = (v[(i+1)%N]-P);
		if( A.y > B.y ) swap(A,B);
		if( A.y <= 0 && 0 < B.y ){
			if( A.rot(B) < 0 ) in =!in;
		}
		if( A.rot(B) == 0 && A.dot(B) <= 0 ){
			return 1;//ON 線上
		}
	}
	return in ? 2:0;//中:外
}
#pragma endregion //contains
#pragma region CGL
//辞書順で比較
bool cmp_x(const Point& p,const Point& q){
	if( p.x != q.x ) return p.x < q.x;
	return p.y < q.y;
}

//凸包を求める
vector<Point> convex_hull(vector<Point> ps,int n){
	sort(ps.begin(),ps.end(), cmp_x);
	int k = 0;//凸包の頂点数
	vector<Point> qs(n*2);//構築中の凸包
	//下側の凸包の作成
	for(int i=0;i<n;++i){
		while(k>1 && (qs[k-1]-qs[k-2]).rot(ps[i]-qs[k-1]) <=0){//<で線上も加える
			k--;
		}
		qs[k++] = ps[i];
	}
	//上側凸包の作成
	for(int i=n-2,t=k;i>=0;i--){
		while(k>t && (qs[k-1]-qs[k-2]).rot(ps[i]-qs[k-1]) <=0){//<
			k--;
		}
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}
#pragma endregion //凸包
#pragma region CGL
double area(vector<Point> poly){
	int size = poly.size();
	double ans = 0;
	for(int i=1;i<size-1;++i){
		ans += (poly[i]-poly[0]).rot(poly[i+1]-poly[0])/2;
	}
	return ans;
}
#pragma endregion //多角形の面積
#pragma region CGL
bool compare_x(Point A,Point B){
	return A.x < B.x;
}
bool compare_y(Point A,Point B){
	return A.y < B.y;
}
//vecはx座標の昇順で渡される
double closest_pair(vector<Point>::iterator itr,int N){
	if(  N <= 1 ) return INF;
	int m = N/2;
	double x = (itr+m)->x;
	double d = min(closest_pair(itr,m),
		closest_pair((itr+m),N-m) );
	
	inplace_merge(itr,itr+m,itr+N,compare_y);

	vector<Point> B;
	for(int i=0;i<N;++i){
		if(fabs((itr+i)->x - x) >= d) continue;
		int Bsize = B.size();
		for(int j=0;j<Bsize;j++){
			double dx,dy;
			dx = (itr+i)->x - B[Bsize-j-1].x;
			dy = (itr+i)->y - B[Bsize-j-1].y;
			if( dy >= d ) break;
			d = min(d,hypot(dx,dy));
		}
		B.push_back(*(itr+i));
	}
	return d;
}
#pragma endregion //最近対 2D
#pragma region CGL
int CircleIntersection(Point A,double AR,Point B,double BR){
	double D = (B-A).norm();
	if( D > AR+BR ){
		return 4;
	}else if( D == AR+BR ){
		return 3;
	}else if( abs(AR-BR) < D  ){//&& D<AR+BR
		return 2;
	}else if(D == abs(AR-BR)){
		return 1;
	}else if(D+AR < BR || D+BR<AR){
		return 0;
	}
	return 0;//
}
#pragma endregion //円と円の位置関係
#pragma region CGL
vector<Point> CircleLine(Point C,double CR,Point A,Point B){
	vector<Point> ans(2);//同じ交点なら同じ値
	double a,b,c;
	a = -(A.y-B.y);
	b = A.x-B.x;
	c = -(a*A.x+b*A.y);

	double l,k,d;
	l = a*a+b*b;
	k = a*C.x + b*C.y+ c;
	d = l*CR*CR-k*k;
	if(d>0){
		double ds = sqrt(d);
		double apl = a/l;
		double bpl = b/l;
		double xc = C.x-apl*k;
		double yc = C.y-bpl*k;
		double xd = bpl*ds;
		double yd = apl*ds;
		Point temp;
		ans[0].x = xc-xd;
		ans[0].y = yc+yd;
		ans[1].x = xc+xd;
		ans[1].y = yc-yd;
	}else if(d==0){
		Point temp;
		temp.x = C.x-a*k/l;
		temp.y = C.y-b*k/l;
		ans[0] = temp;
		ans[1] = temp;
	}else{
		Point temp;
		temp.x = INF;
		temp.y = INF;
		ans[0] = temp;
		ans[1] = temp;
	}
	return ans;
}
#pragma endregion //円と直線の交点,距離チェックする。

#pragma region DSL
class UnionFind{
public:
	int cNum;//要素数
	vector<int> parent;
	vector<int> count;
	vector< vector<int> > GList;
	UnionFind(int n){
		cNum = n;
		parent = vector<int>(n);
		count = vector<int>(n,1);
		GList.resize(n);
		for(int i=0;i<n;++i){
			parent[i] = i;
			GList[i].push_back(i);
		}
	}
	int find(int x){
		if( parent[x] == x ){return x;}
		return parent[x] = find( parent[x] );
	}
	bool same(int x,int y){return find(x) == find(y);}
	int Count(int x){return count[find(x)];}
	void add(int x,int y){//union
		x = find(x);
		y = find(y);
		if( x==y )return;
		parent[x] = y;
		
		count[y] += count[x];
		if( GList[y].size() < GList[x].size() ){
			swap(GList[x],GList[y]);
		}
		GList[y].insert( GList[y].end(),
			GList[x].begin(),GList[x].end() );
	}
};

#pragma endregion //UnionFind
#pragma region DSL
class segment{
};
#pragma endregion //segment tree
#pragma region DSL
class BITree{//1-index
	int N;
	vector<LL> bit;
public:
	BITree(int n){
		N = n;
		bit = vector<LL>(N+1,0);//1-index
	}
	void add(int a,LL w){//aにwを足す
		if( a <= 0 || N < a) return;//a:[1,N]
		for(int i=a;i<=N;i += i & -i){
			bit[i] += w;
		}
	}
	LL sum(int a){//[1,a]の和,a:[1,N]
		/*
		1番目からa番目までの和、1-index
		*/
		LL ret = 0;
		if( a > N ) a = N;
		for(int i=a; i > 0; i -= i & -i){
			ret += bit[i];
		}
		return ret;
	}
};
#pragma endregion //BIndexTree

#pragma region 
template<class T,class U>
istream& operator>>(istream& in,pair<T,U>& P){
	in >> P.first >> P.second;
	return in;
}
#pragma endregion //cin pair<T,U>
#pragma region 
template<class T>
istream& operator>>(istream& in,vector<T>& v){
	int size = v.size();
	for(int i=0;i<size;++i){
		in >> v[i];
	}
	return in;
}
#pragma endregion //cin vector<int>
#pragma region 
//行列の積
namespace mymat{
	LL matMOD = MOD;//初期値10^9 + 7
};
template<class T>
vector< vector<T> > operator*( vector<vector<T> >& A,vector< vector<T> >& B){
	LL mod = mymat::matMOD;
	int R = A.size();
	int cen = A[0].size();
	int C = B[0].size();
	vector< vector<T> > ans(R,vector<T>(C,0) );
	for(int row=0;row<R;++row){
		for(int col=0;col<C;++col){
			for(int inner=0;inner< cen;++inner){
				ans[row][col] = (ans[row][col] + A[row][inner]*B[inner][col])%mod;
				//ans[row][col] = (ans[row][col] + A[row][inner]*B[inner][col]);
			}
		}
	}
	return ans;
}

template<class T>
vector< vector<T> > powMod(vector< vector<T> > mat,LL N,LL mod=MOD){
	mymat::matMOD = mod;
	int R = mat.size();
	int C = mat[0].size();
	//R==C
	vector< vector<T> > I(R,vector<T>(C,0));//単位元
	for(int i=0;i<R && i<C;++i){
		I[i][i] = 1;
	}
	if( N == 0 ){
		return I;
	}
	vector< vector<T> > mul(R,vector<T>(C)),ans(R,vector<T>(C));
	ans = I;
	mul = mat;
	while(N){
		if( N & 1 ){
			ans = ans*mul;
		}
		N >>= 1;
		mul = mul*mul;
	}
	return ans;
}
#pragma endregion //行列

#pragma region
namespace TIME{
time_t start,limit;
void time_start(){start = time(NULL);}
void time_set(int num){limit = num;}//秒
bool check(){return (time(NULL)-start < limit);}
}
#pragma endregion //時間計測

#pragma region
/*
namespace RAND{
mt19937 mt;
void rand_init(){
	random_device rnd;
	mt = mt19937(rnd());
}
int rand(){
	return mt();
}
}
*/
#pragma endregion //乱数

#pragma region
#pragma endregion //

//////////////////
template <typename T>
class segment_base{
	int N;//要素数
	vector< T > dat1;
	T VAL_E;//初期値
public:
	segment_base(){};
	segment_base(int n,T val_E ):N(n),VAL_E(val_E){
		dat1.resize(2*n);
		dat1.assign(2*n,val_E);//初期化
	}
	void init(int n,T val_E){
		N = n;
		VAL_E = val_E;
		dat1.resize(2*n);
		dat1.asigne(2*n,val_E);
	}
	T SELECT(T L,T R){//扱う演算子
		T ans;
		ans = min(L,R);//
		return ans;
	}

	//index番目の値をvalに変更,indexは"0-index"
	void update(int index,T val){
		for(dat1[index+=N] = val;index>1;index>>=1){
			dat1[index>>1] = SELECT(dat1[index],dat1[index^1]);//index+0,+1
		}
	}

	//区間[L,R)のSELECT
	T query(int L,int R){
		T ans = VAL_E;//
		for(L+=N,R+=N; L<R;L>>=1,R>>=1){
			if(L&1) ans = SELECT(ans,dat1[L++]);
			if(R&1) ans = SELECT(ans,dat1[--R]);
		}
		return ans;
	}
};
//////////////////
const int Nmax = 1000;
vector< vector<LL> > dp(Nmax+1,vector<LL>(Nmax+1,0));
vector< LL > inv;
vector<LL> fact(Nmax+1),factInv(Nmax+1);
int N,A,B,C,D;

LL f(int n,int k,int x){//n人からk人グループをx個作る
	if( x == 0 ){
		return 1;
	}
	if( x < C || D < x){
		return 0;
	}
	if( n < k*x ){
		return 0;
	}
	LL ret=1;
	ret = (fact[n]*factInv[n-x*k]) % MOD;
	ret = (ret * factInv[x] ) % MOD;
	ret = (ret * powMod(factInv[k],x) ) % MOD;
	return ret;
}
LL dfs(int k,int n){//n人をk人以下のグループに分ける
	/*
	分ける、分けるがここでは
	k人のグループにしか分けない。
	k-1人以降はdfs(k-1,n-?)に任せる
	*/
	if( n == 0 ){
		return 1;//
	}
	if( k < A || n < A){//グループ人数の制約
		return 0;
	}
	
	if( k == 1 ){//一人のグループは1通り
		//nグループ作られる
		if( C <= n && n <= D ){
			return 1;
		}
		return 0;
	}
	if( dp[k][n] ){
		return dp[k][n];
	}
	LL ans = 0;
	int num = n;
	int K = k;
	
	int Xmax = min(n/k, D);//作れるグループ数の制限
	for(int x=C;x<=Xmax;++x)
	{
		if( n-K*x < 0 ) break;
		if( K*x > n ) break;
		LL res1,res2;
		res1 = 1;
		res2 = 1;
		if( n-K*x == 0 ){
			res2 = 1;
		}else if( n-K*x < A ){
			res2 = 0;
			continue;
		}else if( n-K*x > 0 ){
			res2 = dfs(K-1,n-K*x);
		}
		if( res2 > 0 ){
			res1 = f(n,K,x);
		}
		ans = (ans + (res1*res2)%MOD )%MOD;
	}
	//1グループも作らない
	ans = (ans + dfs(K-1,n) ) % MOD;
	
	dp[k][n] = ans;
	return ans;
}
void solve(){
	cin >> N>>A>>B>>C>>D;
	makeinv(inv,MOD);
	NCK = vector< vector<LL> >(Nmax+1,vector<LL>(Nmax+1,0));
	fact[0] = 1;
	factInv[0] = 1;//
	for(int i=1;i<=Nmax;++i){
		fact[i] = (fact[i-1]*(LL)i) % MOD;
		factInv[i] = (factInv[i-1]*inv[i] ) % MOD;
	}
	LL ans = 0;
	ans = dfs(B,N);
	cout << ans << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
