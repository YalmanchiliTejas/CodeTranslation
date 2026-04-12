#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,s,n) for(int i=s; i<n; i++)
#define ALL(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<double,double> pdd;

const double pi = atan(1.0) * 4.0;
const double EPS = 1e-8;

double cross(pdd x, pdd y) {
	return x.first*y.second - x.second*y.first;
}

double dist(pdd x, pdd y) {
	return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}

int main() {
	int N, M, L;
	while(scanf("%d %d %d", &N, &M, &L), N) {
		vector< vector<pdd> > star(N);
		rep(i, N) {
			int x, y, a, r;
			scanf("%d %d %d %d", &x, &y, &a, &r);
			rep(j, 5) {
				double ang = (72.0 * j + a) * pi / 180.0;
				pdd p(x-r*sin(ang), y+r*cos(ang));
				star[i].push_back(p);
			}
		}
		double cost[100][100];
		rep(i, N) {
			rep(j, N) {
				cost[i][j] = 1e9;
				if(i==j) cost[i][j] = 0.0;
				rep(ii, 5) {
					pdd v1 = pdd(star[i][ii].first - star[i][(ii+2)%5].first, star[i][ii].second - star[i][(ii+2)%5].second);
					rep(jj, 5) {
						pdd v2 = pdd(star[j][jj].first - star[j][(jj+2)%5].first, star[j][jj].second - star[j][(jj+2)%5].second);
						pdd u1 = pdd(star[i][ii].first - star[j][(jj+2)%5].first, star[i][ii].second - star[j][(jj+2)%5].second);
						pdd u2 = pdd(star[j][jj].first - star[i][(ii+2)%5].first, star[j][jj].second - star[i][(ii+2)%5].second);
						pdd w1 = pdd(star[i][ii].first - star[j][jj].first, star[i][ii].second - star[j][jj].second);
						pdd w2 = pdd(-w1.first, -w1.second);
						if( cross(v1,u1)*cross(v1,w1)<-EPS && cross(v2,u2)*cross(v2,w2)<-EPS ) {
							cost[i][j] = 0.0;
						}
					}
				}

				rep(ii, 5) {
					pdd s = star[i][ii];
					pdd t = star[i][(ii+2)%5];
					double alp = 0.0f;
					if( abs(t.first-s.first) < EPS ) {
						rep(jj, 5) {
							double miny = min(s.second, t.second);
							double maxy = max(s.second, t.second);
							if( miny <= star[j][jj].second && star[j][jj].second <= maxy ) {
								cost[i][j] = min(cost[i][j], abs(t.first - star[j][jj].first));
							}
						}
					} else {
						alp = (t.second-s.second)/(t.first-s.first);
						rep(jj, 5) {
							pdd p = star[j][jj];
							double qx = (p.first+alp*p.second-alp*s.second+alp*alp*s.first) / (alp*alp+1.0);
							double qy = alp*(qx-s.first) + s.second;
							pdd q = pdd(qx,qy);
							if( dist(q,s)<dist(t,s) && dist(q,t)<dist(t,s) ) {
								cost[i][j] = min(cost[i][j], dist(p,q));
							}
						}
					}
				}

				rep(ii, 5) {
					rep(jj, 5) {
						cost[i][j] = min(cost[i][j], dist(star[i][ii], star[j][jj]));
					}
				}
			}
		}
		rep(i, N) {
			rep(j, N) {
				cost[i][j] = cost[j][i] = min(cost[i][j], cost[j][i]);
			}
		}
		rep(k, N) {
			rep(i, N) {
				rep(j, N) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
		printf("%.10lf\n", min(cost[M-1][L-1],cost[L-1][M-1]));
	}
	return 0;
}