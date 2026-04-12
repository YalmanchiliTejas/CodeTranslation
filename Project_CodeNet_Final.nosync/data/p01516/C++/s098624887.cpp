#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

#include <complex>
typedef complex<double> P;
double to_rad(int degree){
	return degree*PI/180;
}
//点pを中心としてr(radian)回転            p(0,0)で原点を中心として回転
P rotate(P t, P p, double r){
    //double r=radians(angle);
    double ta=cos(r)*(t.real()-p.real())-sin(r)*(t.imag()-p.imag())+p.real();
    double tb=sin(r)*(t.real()-p.real())+cos(r)*(t.imag()-p.imag())+p.imag();
    return P(ta , tb);
}
// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// 点cが線分a,b上にあるかないか(2)
int is_point_on_line(P a, P b, P c) {
  // |a-c| + |c-b| <= |a-b| なら線分上
  return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}
// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(P a1, P a2, P b1, P b2) {
  if (( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < -EPS ) &&
          ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < -EPS ))
        return true;
  return is_point_on_line(a1, a2, b1) || is_point_on_line(a1, a2, b2) ||
             is_point_on_line(b1, b2, a1) || is_point_on_line(b1, b2, a2);
}
// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}
double distance_ls(P a1, P a2, P b1, P b2) {
  if (is_intersected_ls(a1, a2, b1, b2)) { return 0.0; }
  return min( min(distance_ls_p(a1, a2, b1), distance_ls_p(a1, a2, b2)),
                  min(distance_ls_p(b1, b2, a1), distance_ls_p(b1, b2, a2)) );
}

typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<double> vd;
typedef vector<vd> vvd;
int main(){
	cout.precision(16);
	int n,m,l;
	while(cin>>n>>m>>l,n|m|l){
		vvp stars(n,vp());
		REP(i,n){
			int x,y,a,r;
			cin>>x>>y>>a>>r;
			REP(j,5){
				int degree=(((j*2)%5)*72+a)%360;
				P p=rotate(P(x,y+r),P(x,y),to_rad(degree));
				stars[i].push_back(p);
			}
		}
		vvd dist(n,vd(n));
		REP(i,n){
			REP(j,n){
				if(i==j){
					dist[i][j]=0;
				}else{
					double d=INT_MAX;
					REP(k,5){
						REP(l,5){
							d=min(d,distance_ls(stars[i][k],stars[i][(k+1)%5],stars[j][l],stars[j][(l+1)%5]));
						}
					}
					dist[i][j]=d;
				}
			}
		}

		REP(k,n){
			REP(i,n){
				REP(j,n){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		cout<<dist[m-1][l-1]<<endl;
	}
}