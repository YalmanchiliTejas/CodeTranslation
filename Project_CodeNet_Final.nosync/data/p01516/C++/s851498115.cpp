#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <cstdio>

using namespace std;

const double EPS = 1e-8f;
const double PI = acos(-1.0);
typedef complex<double> P;

struct L { P p, q; L(P p, P q) : p(p), q(q) {} };
double dot(P a, P b) { return real(conj(a)*b); }
double cross(P a, P b) { return imag(conj(a)*b); }

bool ssIntersect(L a, L b){
	if(abs(imag((a.q-a.p)/(b.q-b.p)))<EPS) return false;
	return cross(a.q-a.p, b.p-a.p)*cross(a.q-a.p, b.q-a.p) < 0 &&
    	   cross(b.q-b.p, a.p-b.p)*cross(b.q-b.p, a.q-b.p) < 0;
}

double distLP(L l, P p){
	if(dot(l.q-l.p,p-l.p)<-EPS) return abs(p-l.p);
	if(dot(l.p-l.q,p-l.q)<-EPS) return abs(p-l.q);
	return abs(cross(l.q-l.p,p-l.p))/abs(l.q-l.p);
}

int main(){
	int N, s, g;
	double dist[100][100];
	while(cin >> N >> s >> g && N){
		vector< vector<P> > vp(N);
		for(int i=0;i<N;i++){
			int x, y, a, r; cin >> x >> y >> a >> r;
			for(int j=0;j<5;j++){
				double angle = (90+a+72*j)*PI/180;
				vp[i].push_back(P(x+r*cos(angle),y+r*sin(angle)));
			}
		}
		for(int i=0;i<N;i++){
			dist[i][i] = 0;
			for(int j=i+1;j<N;j++){
				dist[i][j] = 1e12;
				for(int k=0;k<5;k++){
					for(int l=0;l<5;l++){
						dist[i][j] = min(dist[i][j], distLP(L(vp[i][k], vp[i][(k+2)%5]), vp[j][l]));
						dist[i][j] = min(dist[i][j], distLP(L(vp[j][k], vp[j][(k+2)%5]), vp[i][l]));
						if(ssIntersect(L(vp[i][k], vp[i][(k+2)%5]), L(vp[j][l], vp[j][(l+2)%5]))){
							dist[i][j] = 0;
						}
					}
				}
				dist[j][i] = dist[i][j];
			}
		}
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
		printf("%.8lf\n", dist[s-1][g-1]);
	}
}