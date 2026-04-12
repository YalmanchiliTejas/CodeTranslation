#include <complex>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;

#define X real()
#define Y imag()

#define fi first
#define se second

typedef complex<double> PT;
typedef PT VC;
typedef pair<PT,PT> LN;
typedef pair<PT,PT> SG;

const double EPS = 1e-8;

double dot_prod(VC a, VC b) {
	return a.X * b.X + a.Y * b.Y;
}
double cross_prod(VC a, VC b) {
	return a.X * b.Y - a.Y * b.X;
}

double dist_pts_line(PT p, LN l) {
	VC a, b;
	a = l.fi - p;
	b = l.se - p;
	return abs(cross_prod(a,b) / abs(l.fi-l.se));
}

vector<PT> intersec_line_line(LN a, LN b) {
	vector<PT> res;
	if(abs(cross_prod(a.fi-a.se, b.fi-b.se)) < EPS)
		return res;
	if(abs(cross_prod(b.fi-a.fi, b.se-a.fi)) < EPS)
		swap(a.fi, a.se);
	
	VC va, vb, vc;
	double s, t;
	va = b.fi - a.fi;
	vb = b.se - a.fi;
	vc = a.se - a.fi;
	s = cross_prod(va, vc) / cross_prod(va, vb);
	t = cross_prod(vc, vb) / cross_prod(va, vb);
	res.push_back(a.fi + (t * va + s * vb) / (s+t));
	return res;
}

bool on_seg(PT p, SG a) {
	VC b, c;
	b = a.fi - p;
	c = a.se - p;
	return dot_prod(b,c) < EPS && abs(cross_prod(b,c)) < EPS;
}

vector<PT> intersec_seg_seg(SG a, SG b) {
	vector<PT> tmp, res;
	tmp = intersec_line_line(a,b);
	for(int i = 0; i < tmp.size(); i++) {
		if(on_seg(tmp[i], a) && on_seg(tmp[i],b))
			res.push_back(tmp[i]);
	}
	return res;
}


// テ、ツサツ・テ、ツクツ甘・ツケツセテ、ツスツ陛」ツδゥテ」ツつ、テ」ツδ姪」ツδゥテ」ツδェテ・ツ?凖ァツオツ?

double dist_pts_seg(PT p, SG a) {
	double res;
	res = min(abs(a.fi-p), abs(a.se-p));
	if(dot_prod(a.se - a.fi, p - a.fi) > -EPS
			&& dot_prod(a.fi - a.se, p - a.se) > -EPS)
		res = min(res, dist_pts_line(p, a));
	return res;
}

double dist_seg_seg(SG a, SG b) {
	double res;
	res = min(
			min(dist_pts_seg(a.fi,b), dist_pts_seg(a.se,b)),
			min(dist_pts_seg(b.fi,a), dist_pts_seg(b.se,a)) );
	if(intersec_seg_seg(a,b).size())
		res = 0;
	return res;
}

/* //テ・ツケツセテ、ツスツ陛」ツδ?」ツつケテ」ツδ?
int main() {
	SG a(PT(0,0),PT(0,2));
	SG b(PT(-1,1),PT(2,1));
	cout << dist_seg_seg(a,b) << endl;
} // */

//*
int N, M, L;
vector<vector<SG> > star;
double edge[120][120];

#define rep(i,n) for(int i = 0; i < (n); i++)

void init() {
	star.clear();
	rep(i,120) {
		rep(j,120)
			edge[i][j] = 1e9;
		edge[i][i] = 0;
	}
}

int main() {
	while(cin >> N >> M >> L, N || M || L) {
		init();
		M--; L--;
		rep(i,N) {
			int x, y, a, r;
			cin >> x >> y >> a >> r;
			vector<PT> tmp;
			double theta = (a+90) / 180.0 * M_PI;
			double phi = 360.0 / 5.0 / 180.0 * M_PI;
			rep(i,5) {
				tmp.push_back(polar((double)r, theta + phi * i) + PT(x,y));
			//	cout << tmp[i] << endl;
			}
			vector<SG> push;
			rep(i,5) {
				push.push_back(SG(tmp[i],tmp[(i+2)%5]));
			}
			star.push_back(push);
		}

		rep(i,N) {
			for(int j = i+1; j < N; j++) {
				double tmp = 1e9;
				rep(k,5) {
					rep(l, 5) {
						tmp = min(tmp, dist_seg_seg(star[i][k], star[j][l]));
					}
				}
				edge[i][j] = edge[j][i] = tmp;
			}
		}

		rep(i,N) {
			rep(j,N) {
				rep(k,N) {
					edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);
				}
			}
		}
		printf("%.10lf\n", edge[L][M]);
	}
}
// */