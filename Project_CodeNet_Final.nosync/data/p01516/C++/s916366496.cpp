#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

#define EPS 1e-07
#define INF 1e8

template<class T>
struct point{
  T x,y;
  
  point (){}
  point (T _x, T _y) : x(_x), y(_y){}

  point &operator+=(const point &a){ x+=a.x; y+=a.y; }
  point &operator-=(const point &a){ x-=a.x; y-=a.y; }
  point operator+(const point &a)const{ return (point){x+a.x,y+a.y}; }
  point operator-(const point &a)const{ return (point){x-a.x,y-a.y}; }
  operator point<double>()const{ return (point<double>){x,y}; }
};

template<class T>
point<T> operator*(T c,const point<T> &a){ return (point<T>){c*a.x,c*a.y}; }

template<class T>
struct line{
  point<T> a,b;
  operator line<double>()const{ return (line<double>){a,b}; }
};

template<class T>
struct segment{
  point<T> a,b;
 
  segment(){}
  segment(point<T> _a, point<T> _b) : a(_a), b(_b) {}

  operator line<T>()const{ return (line<T>){a,b}; }
};

template<class T>
T dot(const point<T> &a, const point<T> &b){
  return a.x * b.x + a.y * b.y;
}

template<class T>
T cross(const point<T> &a, const point<T> &b){
  return a.x * b.y - b.x * a.y;
}

enum{CCW=1,CW=-1,ON=0};
int ccw(const point<double> &a,const point<double> &b,const point<double> &c){
  double rdir=cross(b-a,c-a);
  if(rdir >  EPS) return CCW;
  if(rdir < -EPS) return CW;
  return ON;
}

template<class T>
T dist2(const point<T> &a, const point<T> &b){
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

template<class T>
double dist2(const segment<T> &S,const point<T> &p){
  if(dot(S.b-S.a,p-S.a)<=0) return dist2(p,S.a);
  if(dot(S.a-S.b,p-S.b)<=0) return dist2(p,S.b);
  return (double)cross(S.b-S.a,p-S.a)*cross(S.b-S.a,p-S.a)/dist2(S.a,S.b);
}

template<class T>
double dist(const point<T> &a, const point<T> &b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

template<class T>
double dist(const segment<T> &S, const point<T> &p){
  if(dot(S.b-S.a,p-S.a)<=0) return dist(p,S.a);
  if(dot(S.a-S.b,p-S.b)<=0) return dist(p,S.b);
  return abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);
}

bool intersect(const segment<double> &S1,const segment<double> &S2){
  if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
     || max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
     || max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
     || max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
  return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b) <=0 
    && ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b) <= 0;
}

template<class T>
double dist(const segment<T> &S1, const segment<T> &S2){
  if(intersect(S1,S2)) return 0;
  return sqrt(min(min(dist2(S1,S2.a),dist2(S1,S2.b)),
		  min(dist2(S2,S1.a),dist2(S2,S1.b))));
}

point<double> get_point(double x, double y, double a, double r, long long int tt){
  const double cnt_ang  = M_PI * ( a + tt * 144 + 90 ) / 180;
  const double cnt_x    = 1.00 * r * cos( cnt_ang ) + x;
  const double cnt_y    = 1.00 * r * sin( cnt_ang ) + y;
  
  return point<double>(cnt_x, cnt_y);
}

int main() {

  while( true ) {

    long long int n, m, l;
    cin >> n >> m >> l;
    if ( n == 0 ) break;

    vector< vector< segment<double> > > stars;

    for ( long long int i = 0; i < n; i++ ) {
      double in_x, in_y, in_a, in_r;
      
      cin >> in_x >> in_y >> in_a >> in_r;
      
      vector<segment<double> > segments;
      
      for(long long int tt = 0; tt < 5; tt++){
	segments.push_back(segment<double>(get_point(in_x, in_y, in_a, in_r, tt), 
					   get_point(in_x, in_y, in_a, in_r, (tt + 1) % 5)));
      }

      stars.push_back(segments);
    }

    

    double len[101][101];
    for ( long long int i = 0; i < n; i++ ) {
      for ( long long int j = 0; j < n; j++ ) {
	len[i][j] = i == j ? 0 : INF;
      }
    }  
    
    for( long long int from_star = 0; from_star < n; from_star++){
      vector<segment<double> > from_segs = stars[from_star];
      
      for(long long to_star = from_star + 1; to_star < n; to_star++){
	vector<segment<double> > to_segs = stars[to_star];
	
	for(long long from_seg_no = 0; from_seg_no < 5; from_seg_no++){
	  for(long long to_seg_no = 0; to_seg_no < 5; to_seg_no++){
	    const double dist_ss = dist(from_segs[from_seg_no], to_segs[to_seg_no]);
	    
	    len[from_star][to_star] = min(len[from_star][to_star], dist_ss);
	    len[to_star][from_star] = min(len[to_star][from_star], dist_ss);
	    //cout << from_star << "(" << from_seg_no << ")"  << " " << to_star << "(" << to_seg_no << ")" << " " << dist_ss << endl;
	  }
	}
      }  
    }

    for ( long long int k = 0; k < n; k++ ) {    
      for ( long long int i = 0; i < n; i++ ) {
	for ( long long int j = 0; j < n; j++ ) {
	  len[i][j] = min( len[i][j], len[i][k] + len[k][j] );
	}
      }
    }

    cout << fixed << setprecision(10) << len[m-1][l-1] << endl;

  }

  return 0;
}