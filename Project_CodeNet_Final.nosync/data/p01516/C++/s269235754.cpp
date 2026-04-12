#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

// XY座標
#define X real()
#define Y imag()

const double EPS = 1e-6;
const double INF = 1e+12;
const double PI = acos(-1.0);
typedef complex<double> P;

// 内積(dot product) a・b = |a||b|cosθ 
double dot(P a, P b){
	return real( conj(a) * b );
}

// 外積(cross product) |a×b| = |a||b|sinθ
double cross(P a, P b){
	return imag( conj(a) * b );
}

// 度からラジアンに変換する.
double to_rad(double deg){
	return deg * PI / 180.0;
}

// 原点を軸に点 p を a ラジアンだけ回転した点を返す.
P rot(P p, double a){
	double x = p.X * cos(a) - p.Y * sin(a);
	double y = p.X * sin(a) + p.Y * cos(a);
	return P(x,y);
}

// 点 a を軸に点 b を angle ラジアンだけ回転した点を返す.
P rot2(P a, P b, double angle){
	P p = b - a;
	return rot( p , angle ) + a;
}

// CCW : 反時計回り (Counter Clock Wise)
// CW : 時計回り (Clock Wise)
enum {CCW=1, CW=-1, ON=0};
// * 3点がどちら回りであるか返す, 3点が1直線に乗っているときは ON を返す
int ccw(const P &a, P b, P c) {
	b-=a, c-=a;
	if( cross(b,c) >  EPS ) return CCW;
	if( cross(b,c) < -EPS ) return CW;
	if(dot(b, c) < -EPS )   return +2;
	if(dot(b, b) + EPS < dot(c, c) ) return -2;
	return ON;
}

// 線分クラス
struct Segment{
	P a, b;
	Segment(P a_, P b_){
		a = a_; b = b_;
	}
	
	// 点 p と線分の距離を返す.
	double distance(P p){
		if( dot(b-a,p-a) < EPS ) return abs(p-a);
		if( dot(a-b,p-b) < EPS ) return abs(p-b);
		return abs( cross(b-a,p-a) ) / abs(b-a) ;
	}
	// 線分 s と交差しているかどうかを返す.
	bool is_intersection(const Segment& s){
		return ( ccw(a, b, s.a)   * ccw(a, b, s.b) <= 0 && 
		         ccw(s.a, s.b, a) * ccw(s.a, s.b, b) <= 0 );
	}
	// 点 p が線分上にあるかどうか
	bool contain(P p) { return (abs(a-p) + abs(p-b) < abs(a-b) + EPS); }
	// 線分と線分の距離
	double distance(Segment s) {
		if( is_intersection(s) ) return 0.0;
		return min( min(distance(s.a), distance(s.b)), min(s.distance(a), s.distance(b)) );
	}
	// デバッグ出力
	void print(){
		printf("line(%f,%f,%f,%f);\n", a.X ,a.Y, b.X, b.Y );
	}
};

int main(){
	// n := 星の数, m := スタート, l := ゴール
	int n, m, l;
	while( scanf("%d %d %d", &n, &m, &l) , n || m || l ){
		m--; l--;
		// v[i] := i 番目の星 (5つの線分)
		vector< vector<Segment> > v;
		 
		for(int i=0 ; i < n ; i++ ){
			int x, y, a, r;
			scanf("%d %d %d %d", &x, &y, &a, &r );
			double angle = to_rad( a + 90 );
			P p1( x + r*cos(angle) , y + r*sin(angle) );
			P p2 = rot2( P(x,y) , p1 , to_rad(72) );
			P p3 = rot2( P(x,y) , p2 , to_rad(72) );
			P p4 = rot2( P(x,y) , p3 , to_rad(72) );
			P p5 = rot2( P(x,y) , p4 , to_rad(72) );
			// vs := 5 つの線分
			vector<Segment> vs;
			vs.push_back( Segment(p1,p3) );
			vs.push_back( Segment(p3,p5) );
			vs.push_back( Segment(p5,p2) );
			vs.push_back( Segment(p2,p4) );
			vs.push_back( Segment(p4,p1) );
			v.push_back( vs );
		}
		double G[101][101];
		for(int i=0 ; i < 101 ; i++ ){
			for(int j=0 ; j < 101 ; j++ ){
				G[i][j] = (i == j)? 0 : INF;
			}
		}
		for(int i=0 ; i < v.size() ; i++ ){
			for(int j=i+1 ; j < v.size() ; j++ ){
				double d = INF;
				for(int k1 = 0 ; k1 < v[i].size() ; k1++ ){
					for(int k2 = 0 ; k2 < v[j].size() ; k2++ ){
						Segment s1 = v[i][k1];
						Segment s2 = v[j][k2];
						d = min( d , s1.distance(s2) );
					}
				}
				G[i][j] = G[j][i] = d;
			} 
		}
		
		for(int k=0 ; k < n ; k++ ){
			for(int i=0 ; i < n ; i++ ){
				for(int j=0 ; j < n ; j++ ){
					G[i][j] = min( G[i][j] , G[i][k] + G[k][j] );
				}
			}
		}
		printf("%.8f\n", G[m][l] );
	}
}