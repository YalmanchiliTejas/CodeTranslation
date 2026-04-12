#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

// * XYツ催?標
#define X real()
#define Y imag()

// * ツ点ツづ個表ツ個サ
typedef complex<double> P;

// * ツ仰鳴容ツつキツづゥツ古ォツ債キツε?
const double EPS = 1e-6;
// * Infinity
const double INF = 1e12;
// * ツ円ツ偲シツ猟ヲ
const double PI = acos(-1.0);
// * Infinity 2
const P INF_P(INF,INF);

// * complex<double> ツづ個渉?渉伉づーツ津ィツ義ツつキツづゥ
namespace std {
	bool operator < (const P& a, const P& b) {
		return (real(a) != real(b))? real(a) < real(b) : imag(a) < imag(b);
	}
}

// * 2ツ点ツ甘板づ個仰猟猟」
double dist(P p1, P p2) {
	return abs(p1 - p2);
}

// * 2ツづつづ個スツカツδ可ーツつェツ督卍つオツつ「ツつゥツづ?つ、ツつゥ
bool equal(double a, double b) {
	return ( fabs( a - b ) < EPS );
}
// * 2ツづつづ個ベツクツトツδ仰つェツ督卍つオツつ「ツつゥツづ?つ、ツつゥ
bool eq_v(P a, P b) {
	return ( equal( a.X, b.X ) && equal( a.Y, b.Y ) );
}

// * ツ禿?静?(dot product) : aツ・b = |a||b|cosツδヲ
double dot(P a, P b) {
	return real( conj(a) * b );
}

// * ツ外ツ静?(cross product) : aツ×b = |a||b|sinツδヲ
double cross(P a, P b) {
	return imag( conj(a) * b ) ;
}

// CCW : ツ板スツ篠楪計ツ嘉アツづィ (Counter Clock Wise)
// CW : ツ篠楪計ツ嘉アツづィ (Clock Wise)
enum {CCW=1, CW=-1, ON=0};
// * 3ツ点ツつェツづ?つソツづァツ嘉アツづィツづ?つ?づゥツつゥツ陛板つキ, 3ツ点ツつェ1ツ陳シツ静シツづ可湘ヲツづ?づ?つ「ツづゥツづ?つォツづ?ON ツづーツ陛板つキ
int ccw(const P &a, P b, P c) {
    b-=a, c-=a;
    if( cross(b,c) >  EPS ) return CCW; // CCW : ツ板スツ篠楪計ツ嘉アツづィ
    if( cross(b,c) < -EPS ) return CW;  // CW : ツ篠楪計ツ嘉アツづィ
    if(dot(b, c) < -EPS )   return +2;  // c--a--b on line
    if(dot(b, b) + EPS < dot(c, c) ) return -2; // a--b--c on line ???
    return ON;
}

// ツδ可ジツアツδ督つゥツづァツ度ツ青板づ鳴陛渉環キツつオツづ?陛板つキ
double to_deg(double rad) {
	return rad * 180.0 / PI;
}

// ツ度ツ青板つゥツづァツδ可ジツアツδ督づ可陛渉環キツつオツづ?陛板つキ
double to_rad(double deg) {
	return deg * PI / 180.0;
}

// ツ個エツ点ツづーツ篠イツづ可点 p ツづーツ角ツ度 a (ツδ可ジツアツδ?ツつセツつッツ嘉アツ転ツつウツつケツつスツ点ツづーツ陛板つキ
P rot(P p, double a){
	double x = p.X * cos(a) - p.Y * sin(a);
	double y = p.X * sin(a) + p.Y * cos(a);
	return P(x,y);
}

// ツ点 a ツづーツ篠イツづ可点 b ツづーツ角ツ度 a (ツδ可ジツアツδ?ツつセツつッツ嘉アツ転ツつウツつケツつスツ点ツづーツ陛板つキ
P rot2(P a, P b, double angle){
	P p = b - a;
	return rot( p , angle ) + a;
}

// ツ静シツ閉ェツクツδ可ス
struct Segment{
    P a, b;
    Segment(P a_, P b_){
        a = a_; b = b_;
    }
    // ツ点 p ツづ?静シツ閉ェツづ個仰猟猟」ツづーツ陛板つキ.
    double distance(P p){
        if( dot(b-a,p-a) < EPS ) return abs(p-a);
        if( dot(a-b,p-b) < EPS ) return abs(p-b);
        return abs( cross(b-a,p-a) ) / abs(b-a) ;
    }
    // ツ静シツ閉ェ s ツづ?古ーツ債キツつオツづ?つ「ツづゥツつゥツづ?つ、ツつゥツづーツ陛板つキ.
    bool is_intersection(const Segment& s){
        return ( ccw(a, b, s.a)   * ccw(a, b, s.b) <= 0 && 
                 ccw(s.a, s.b, a) * ccw(s.a, s.b, b) <= 0 );
    }
    // ツ点 p ツつェツ静シツ閉ェツ湘」ツづ可つ?づゥツつゥツづ?つ、ツつゥ
    bool contain(P p) { return (abs(a-p) + abs(p-b) < abs(a-b) + EPS); }
    // ツ静シツ閉ェツづ?静シツ閉ェツづ個仰猟猟」
    double distance(Segment s) {
        if( is_intersection(s) ) return 0.0;
        return min( min(distance(s.a), distance(s.b)), min(s.distance(a), s.distance(b)) );
    }
    // ツデツバツッツグツ出ツ療?
    void print(){
        printf("line(%f,%f,%f,%f);\n", a.X ,a.Y, b.X, b.Y );
    }
};

int main(){
    // n := ツ青ッツづ個青? m := ツスツタツーツト, l := ツゴツーツδ?
    int n, m, l;
    while( scanf("%d %d %d", &n, &m, &l) , n || m || l ){
        m--; l--;
        // v[i] := i ツ氾板姪堋づ個青ッ (5ツづつづ個静シツ閉ェ)
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
            // vs := 5 ツづつづ個静シツ閉ェ
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