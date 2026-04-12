#include <iostream>
#include<string>
#include <complex>
#include<list>
#include<float.h>
#include <functional>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define REP0(i,n)   REP(i,0,n)
#define foreach(it,o) for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
typedef complex<double> P;
bool operator <(const P& a, const P& b) {
	return abs(a) < abs(b);
}

int N, M, L;

double dot(P a, P b) {
	return real(conj(a) * b);
}
double cross(P a, P b) {
	return imag(conj(a) * b);
}

double ex(P a,P b,P c){
	return cross(b-a,c-a);
}

int ccw(P a, P b, P c) {
 b -= a; c -= a;
 if (cross(b, c) > DBL_EPSILON) return +1; // counter clockwise
 if (cross(b, c) < -DBL_EPSILON) return -1; // clockwise
 if (dot(b, c) < -DBL_EPSILON) return +2; // c--a--b on line
 if (norm(b) < norm(c) - DBL_EPSILON) return -2; // a--b--c on line
 return 0; // a--c--b on line (or b == c)
}

bool isIntersectSS(P a1, P a2, P b1, P b2) {
	 return ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 &&
	 ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0;
}
double DistanceSP(P a, P b, P c) {
	if (dot(b - a, c - a) < DBL_EPSILON)
		return abs(c - a);
	if (dot(a - b, c - b) < DBL_EPSILON)
		return abs(c - b);
	return abs(cross(b - a, c - a))/abs(a-b);
}
double DistaiceSS(P a, P b, P c, P d) {
	if (isIntersectSS(a, b, c, d)) {
		return 0.0;
	}
	return min(min(DistanceSP(a, b, c), DistanceSP(a, b, d)),
			min(DistanceSP(c, d, a), DistanceSP(c, d, b)));
}

vector<vector<double> > links;

struct Star {
	P p;
	int a;
	int r;
	Star(P p, int a, int r) :
			p(p), a(a), r(r) {
		initVertex();
	}
	vector<P> vertex;
private:
	void initVertex() {
		for (int i = 0; i < 5; i++) {
			double theta = M_PI / 2 + 2 * i * M_PI / 5 + a * M_PI / 180;
			vertex.push_back(
					P(p.real() + r * cos(theta), p.imag() + r * sin(theta)));
		}
	}
};
vector<pair<int,int> > edges;

double getLength(Star p1, Star p2) {
	double m = DBL_MAX;
	foreach(ea,edges){
		P a1=p1.vertex[(*ea).first];
		P a2=p1.vertex[(*ea).second];
		foreach(eb,edges){
			P b1=p2.vertex[(*eb).first];
			P b2=p2.vertex[(*eb).second];
//			cout<< a1<<a2<< b1<< b2 <<endl;
//			cout<< DistaiceSS(a1, a2, b1, b2) <<endl;
			m = min(m, DistaiceSS(a1, a2, b1, b2));
		}

	}
	return m;
}
int x, y, a, r;

double dijk(int start, int goal) {
	vector<double> memo(N, DBL_MAX);
	priority_queue<pair<double,int> > up;
	up.push(make_pair(0, start));
	memo[start] = 0;
	while (!up.empty()) {
		double cost = -up.top().first;
		int pos = up.top().second;

		up.pop();
		if (memo[pos] < cost)
			continue;
		if (pos == goal)
			return cost;
		REP0(next,N) {
			if (links[pos][next] >= 0) {
				double ncost = cost + links[pos][next];
				if (memo[next] > ncost) {
					memo[next] = ncost;
					up.push(make_pair(-ncost, next));
				}
			}
		}
	}
	return -1;
}

int main() {
	edges.push_back(make_pair(0,2));
	edges.push_back(make_pair(0,3));
	edges.push_back(make_pair(1,4));
	edges.push_back(make_pair(1,3));
	edges.push_back(make_pair(2,4));
	while (true) {
		cin >> N >> M >> L;
		if (N == 0 && M == 0 && L == 0) {
			break;
		}
		links.clear();
		vector<Star> stars;

		for (int i = 0; i < N; i++) {
			cin >> x >> y >> a >> r;
			stars.push_back(Star(P(x, y), a, r));
		}
		for (int i = 0; i < N; i++) {
			vector<double> ld;
			for (int j = 0; j < N; j++) {
				ld.push_back(i==j?0:getLength(stars[i], stars[j]));
			}
			links.push_back(ld);
		}
		cout.width(10);
		//cout << dijk(M - 1, L - 1) << endl;
		printf("%.8lf\n", dijk( M-1 , L - 1));
	}
	return 0;
}