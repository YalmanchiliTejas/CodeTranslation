#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
  
struct line: public vector< complex<double> >{
  line(){resize(2);};
  line( complex<double> a, complex<double> b){
    push_back(a);
    push_back(b);
  }
};
struct circle {
  complex<double> p; double r;
  circle():p(0,0),r(0){};
  circle(complex<double> p, double r) : p(p),r(r){}
};
typedef complex < double > P;
typedef line               L;
typedef pair < P, P >      Ls;
typedef vector< P >        G;
typedef vector< P >        Ps;
typedef vector< L >        LLL;
typedef circle             C;
const double EPS = 1e-10;
const double INF = 1e8;
bool   eq(P,P); //点:点 同一判定
double cross(P,P); //外積
double dot(P,P); //内積
int    ccw(P,P,P); //3点の位置関係
bool   parallel(L,L); // 直線//直線
bool   orthogonal(L,L); //直線⊥直線
bool   intersect(L,L); //線分:線分交差
bool   intersect(L,P); //線分:点交差
bool   intersect(Ls,Ls); //直線:直線交差
bool   intersect(Ls,L); //直線:線分交差
bool   intersect(Ls,P); //直線:点交差
int    intersect(C,L); //円:線分交点数
bool   intersect(C,Ls); //円:直線交差
bool   intersect(C,C); //円:円交差
bool   intersect(C,P); //円:点交差
double distancion(L,L); //線分:線分の距離(iteratorのdistanceと被るから留意)
double distance(L,P); //線分:点の距離
double distance(P,P); //点:点の距離
double distance(Ls,P); //直線:点距離
double distance(Ls,Ls); //直線:直線距離
double distance(Ls,L); //直線:線分距離
P      crosspoint(L,L); //線分:線分交点計算
L      crosspoint(C,Ls); //円:直線交点計算
L      crosspoint(C,L); //円:線分交点計算
L      crosspoint(C,C); //円:円交点計算
int    contains(G,P); //図形:点内包判定
bool   contains(C,P);
double area2(G); //面積
bool   isconvex(G); //凸性判定
Ps     convex(G); //凸包
  
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
L llcomb(Ls a){
  L line( a.fr, a.sc);
  return line;
}
Ls llrcomb(L a){
  Ls line( a[0], a[1]);
  return line;
}
bool eq( P a, P b){ //OK
  return abs( a - b) < EPS;
}
double cross( P a,  P b){ //OK
  return imag( conj(a) * b);
}
double dot( P a, P b){ //OK
  return real( conj(a) * b);
}
P projection( L l, P p) { //OK
  double t = dot( p - l[0], l[0] - l[1]) / norm( l[0] - l[1]);
  return l[0] + t * ( l[0] - l[1]);
}
P reflection( L l, P p) {
  return p + 2.0 * ( projection( l, p) - p);
}
int ccw( P a, P b, P c){  //OK
  b -= a, c -= a;
  if(cross(b,c) > 0)    return +1;  // a → b で 反時計方向におれて c
  if(cross(b,c) < 0)    return -1; // a → b で 時計方向におれて c
  if(dot(b,c) < 0)      return +2;  // c -- a -- b
  if(norm(b) < norm(c)) return -2; // a -- b -- c
                        return 0;  // a -- c -- b
}
bool intersect( L a, L b){ //OK
  return ccw( a[0], a[1], b[0]) * ccw( a[0], a[1], b[1]) <= 0 &&
    ccw( b[0], b[1], a[0]) * ccw( b[0], b[1], a[1]) <= 0;
}
bool intersect( L a, P p){ //OK
   return abs( a[0] - p) + abs( a[1] - p) - abs( a[1] - a[0]) < EPS;
}
bool intersect( Ls l, Ls m) { //OK
  return abs(cross(l.sc-l.fr, m.sc-m.fr)) > EPS ||
         abs(cross(l.sc-l.fr, m.fr-l.fr)) < EPS;
}
bool intersect(Ls l, L s) { //OK
  return cross( l.sc - l.fr, s[0] - l.fr) *
         cross( l.sc - l.fr, s[1] - l.fr) < EPS;
}
bool intersect(Ls l, P p) { //OK
  return abs( cross( l.sc - p, l.fr - p)) < EPS;
}
bool intersect( C c, Ls s){ //OK
  return distance( s, c.p) <= c.r + EPS;
}
bool intersect( C a, C b){ //OK
  return ( norm( a.p - b.p) - ( a.r + b.r) * ( a.r + b.r) < EPS) &&
    ( norm( a.p - b.p) - ( a.r - b.r) * ( a.r - b.r) > -EPS);
}
int intersect( C c, L l){ //OK
  if( norm( projection( l, c.p) - c.p) - c.r * c.r > EPS) return 0;
  const double d1 = abs( c.p - l[0]), d2 = abs( c.p - l[1]);
  if( d1 < c.r + EPS && d2 < c.r + EPS) return 0;
  if( d1 < c.r - EPS && d2 > c.r + EPS
      || d1 > c.r + EPS && d2 < c.r - EPS ) return 1;
  const P h = projection( l, c.p);
  if( dot( l[0] - h, l[1] - h) < 0) return 2;
  return 0;
}
bool intersect( C c, P p){ //OK
  return abs( abs( p - c.p) - c.r ) < EPS;
}
double distance( L s, P p){ //OK
  P r = projection(s, p);
  if ( intersect( s, r)) return abs( r - p);
  return min( abs( s[0] - p), abs( s[1] - p));
}
double distancion( L a, L b){ //OK
  if(intersect( a, b)) return 0;
  return min( min( distance( a, b[0]), distance( a, b[1])),
              min( distance( b, a[0]), distance( b, a[1])));
}
double distance( Ls l, P p) { //OK
  return abs(p - projection( llcomb(l), p));
}
double distance( Ls l, Ls m) { //OK
  return intersect( l, m) ? 0 : distance( l, m.fr);
}
double distance( Ls l, L s) { //OK
  if (intersect(l, s)) return 0;
  return min(distance(l, s[0]), distance(l, s[1]));
}
double distance( P a, P b){ //OK
  return abs( a - b);
}
bool parallel( L a, L b){
  return abs( cross( a[1] - a[0], b[1] - b[0])) < EPS;
}
bool orthogonal( L a, L b){
  return dot( a[0] - a[1], b[0] - b[1]) < EPS;
}
#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1) % P.size()]
enum { OUT, ON, IN };
int contains(G Q, P p){ //OK
  bool in = false;
  for(int i = 0 ; i < Q.size() ; i++ ){
    P a = curr(Q,i) - p, b = next(Q,i) - p;
    if(imag(a) > imag(b)) swap(a,b);
    if(imag(a) <= 0 && 0 < imag(b) && cross(a,b) < 0) in = !in;
    if(cross(a,b) == 0 && dot(a,b) <= 0) return ON;
  }
  return in ? IN : OUT;
}
bool contains(C c,P p){
  return abs( c.p - p) < c.r + EPS;
}
double area2(G p){ //OK
  double A = 0;
  for (int i = 0; i < p.size(); ++i){
    A += cross(curr(p, i), next(p, i));
  }
  return A;
}
bool isconvex(G p) { // OK
  for (int i = 0; i < p.size(); ++i){
    if (ccw(prev(p, i), curr(p, i), next(p, i)) > 0) return false;
  }
  return true;
}
Ps convex(Ps ps) { //n>=3 OK
  int k = 0;
  sort(ps.begin(), ps.end());
  Ps ch(2 * ps.size());
  for (int i = 0; i < ps.size(); ch[k++] = ps[i++]){
    while (k >= 2 and ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  }
  for (int i = ps.size()-2, t = k+1; i >= 0; ch[k++] = ps[i--]){
    while (k >= t and ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  }
  ch.resize(k-1);
  return ch;
}
P crosspoint(L l, L m) { //OK
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  return m[0] + B / A * (m[1] - m[0]);
}
L crosspoint( C c, Ls l) { //OK
  const P hp = projection( llcomb(l), c.p), h =  hp - c.p;
  const double d2 = norm(h);
  P v = sqrt( c.r * c.r - d2) * ( l.sc - l.fr) / abs( l.sc - l.fr);
  return L(hp - v, hp + v);
}
L crosspoint( C c, L l) { //OK
  if(intersect(c, l) == 2) return crosspoint(c, llrcomb(l));
  L ret = crosspoint(c, llrcomb(l));
  if(dot(l[0] - ret[0], l[1] - ret[0]) < 0) ret[1] = ret[0];
  else ret[0] = ret[1];
  return ret;
}
L crosspoint(C c1, C c2){ //OK
  double d = abs(c1.p - c2.p);
  double s = (c1.r + c2.r + d) / 2;
  double S = sqrt( s * ( s - c1.r) * ( s - c2.r) * ( s - d));
  double h = 2 * S / d;
  P v = ( c2.p - c1.p) / ( abs( c2.p - c1.p));
  double m = sqrt( c1.r * c1.r - h * h);
  return L( c1.p + m * v + h * v * P(0,1), c1.p + m * v - h * v * P(0,1));
}
double Degree_to_Radian(double n){
  return n * M_PI / 180.0;
}
double Radian_to_Degree(double n){
  return n * 180.0 / M_PI;
}
/* ここまでテンプレート */
 
typedef pair< double , int > Pi;
double used[100];
double info[100][100];
int n, m, l;
L stars[100][5];
 
void add( int x, int y, int a, int r, const int z){
  G hosi(5);
  for(int i = 0 ; i < 5 ; i++ ){
    double theta = Degree_to_Radian(a + 72 * i);
    double nx = r * sin( theta ), ny = r * cos( theta );
    hosi[i] = P( x - nx, y + ny);
  }
  for(int i = 0 ; i < 5 ; i++ ){
    stars[z][i] = L( hosi[i * 2 % 5], hosi[(i + 1) * 2 % 5]);
  }
}
double dist( LLL a, LLL b){
  double ret = INF;
  for(int i = 0 ; i < a.size() ; i++ ){
    for(int j = 0 ; j < b.size() ; j++ ){
      ret = min( ret, distancion( a[i], b[i]));
    }
  }
  return ret;
}
double Dijkstra(){
  priority_queue< Pi , vector< Pi > , greater< Pi > > que;
  fill_n( used, 100, INF);
  que.push( Pi( 0.0, m));
  used[m] = 0.0;
  while(!que.empty()){
    Pi p = que.top(); que.pop();
    if(p.sc == l) return p.fr;
    if(used[p.sc] < p.fr) continue;
    for(int i = 0 ; i < n ; i++ ){
      if(info[p.sc][i] + p.fr < used[i]){
        que.push( Pi( info[p.sc][i] + p.fr, i));
        used[i] = info[p.sc][i] + p.fr;
      }
    }
  }
}
  
int main(){
  while(cin >> n >> m >> l, l){
    m--, l--;
    for(int i = 0 ; i < n ; i++ ){
      int x, y, a, r;
      cin >> x >> y >> a >> r;
      add( x, y, a, r, i);
    }
  
    for(int i = 0 ; i < n ; i++ ){
      for(int j = i + 1 ; j < n ; j++ ){
        double dist = INF;
        for(int a = 0 ; a < 5 ; a++ ){
          for(int b = 0 ; b < 5 ; b++ ){
            dist = min( dist, distancion( stars[i][a], stars[j][b]));
          }
        }
        info[i][j] = info[j][i] = dist;
      }
    }
    cout << fixed << setprecision(10) << Dijkstra() << endl;
  }
}