#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef complex < double > P;
typedef pair < P, P >      L;
typedef pair < P, P >      Ls;
const double EPS = 1e-10;
const double INF = 1e8;
double cross( P a,  P b){ //OK
  return imag( conj(a) * b);
}
double dot( P a, P b){ //OK
  return real( conj(a) * b);
}
int ccw( P a, P b, P c){  //OK
  b -= a, c -= a;
  if(cross(b,c) > 0)    return +1;  // a → b で 反時計方向におれて c
  if(cross(b,c) < 0)    return -1; // a → b で 時計方向におれて c
  if(dot(b,c) < 0)      return +2;  // c -- a -- b
  if(norm(b) < norm(c)) return -2; // a -- b -- c
                        return 0;  // a -- c -- b
}
P projection( L l, P p) { //OK
  double t = dot( p - l.fr, l.fr - l.sc) / norm( l.fr - l.sc);
  return l.fr + t * ( l.fr - l.sc);
}
bool intersect( L a, P p){ //OK
   return abs( a.fr - p) + abs( a.sc - p) - abs( a.fr - a.sc) < EPS;
}
bool intersect( L a, L b){ //OK
  return ccw( a.fr, a.sc, b.fr) * ccw( a.fr, a.sc, b.sc) <= 0 &&
    ccw( b.fr, b.sc, a.fr) * ccw( b.fr, b.sc, a.sc) <= 0;
}
double distance( L s, P p){ //OK
  P r = projection(s, p);
  if ( intersect( s, r)) return abs( r - p);
  return min( abs( s.fr - p), abs( s.sc - p));
}
double distancion( L a, L b){ //OK
  if(intersect( a, b)) return 0;
  return min( min( distance( a, b.fr), distance( a, b.sc)),
              min( distance( b, a.fr), distance( b, a.sc)));
}
double Degree_to_Radian(double n){
  return n * M_PI / 180.0;
}
double Radian_to_Degree(double n){
  return n * 180.0 / M_PI;
}
/* ここまでテンプレート */
double info[100][100];
int n, m, l;
L stars[100][5];
int table[][5] = {{0,0,1,1,2},{2,3,3,4,4}};
P hosi[5];
void add( double x, double y, double a, double r, int z){
  for(int i = 0 ; i < 5 ; i++ ){
    double theta = Degree_to_Radian(a + 72 * i);
    double nx = r * sin( theta ), ny = r * cos( theta );
    hosi[i] = P( x - nx, y + ny);
  }
  for(int i = 0 ; i < 5 ; i++ ){
    stars[z][i] = L( hosi[table[0][i]], hosi[table[1][i]]);
  }
}
int main(){ //vectorが重いかも
  while(scanf("%d%d%d", &n, &m, &l), n|m|l){
    m--, l--;
    for(int i = 0 ; i < n ; i++ ){
      double x, y, a, r;
      scanf("%lf%lf%lf%lf", &x, &y, &a, &r);
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
    for(int k = 0; k < n; k++ ){
      for(int i = 0; i < n; i++ ){
        for(int j = 0; j < n; j++ ){
          info[i][j] = min( info[i][j], info[i][k] + info[k][j]);
        }
      }
    }
    printf("%.10f\n", info[m][l]);
  }
}