#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
	int cx, cy;
};
struct Point2 {
	long double cx, cy;
};

long double dst(Point A1, Point A2) {
	return sqrtl((A1.cx - A2.cx) * (A1.cx - A2.cx) + (A1.cy - A2.cy) * (A1.cy - A2.cy));
}
long double dst2(Point A1, Point2 A2) {
	return sqrtl((1.0L * A1.cx - A2.cx) * (1.0L * A1.cx - A2.cx) + (1.0L * A1.cy - A2.cy) * (1.0L * A1.cy - A2.cy));
}

int cross(Point A1, Point A2) {
	return A1.cx * A2.cy - A1.cy * A2.cx;
}
int dot(Point A1, Point A2) {
	return A1.cx * A2.cx + A1.cy * A2.cy;
}
int norm(Point A1) {
	return A1.cx * A1.cx + A1.cy * A1.cy;
}

int ccw(Point p0, Point p1, Point p2) {
	Point a = Point{ p1.cx - p0.cx, p1.cy - p0.cy };
	Point b = Point{ p2.cx - p0.cx, p2.cy - p0.cy };
	if (cross(a, b) > 0) return 1;
	if (cross(a, b) < 0) return -1;
	if (dot(a, b) < 0) return 2;
	if (norm(a) < norm(b)) return -2;
	return 0;
}
bool intersect(Point p1, Point p2, Point p3, Point p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

int N; long double dist[109][109]; Point S, G, A[10009];

int main() {
	cin >> S.cx >> S.cy >> G.cx >> G.cy >> N;
	for (int i = 0; i < N; i++) cin >> A[i].cx >> A[i].cy;
	
	bool flag = false;
	for (int i = 0; i < N; i++) {
		bool p1 = intersect(A[i], A[(i + 1) % N], S, G);
		if (p1 == true) { flag = true; }
	}

	if (flag == true) {
		for (int i = 0; i < N + 2; i++) { for (int j = 0; j < N + 2; j++) dist[i][j] = 1e9; dist[i][i] = 0; }
		for (int i = 0; i < N; i++) {
			dist[i][(i + 1) % N] = dst(A[i], A[(i + 1) % N]);
			dist[(i + 1) % N][i] = dist[i][(i + 1) % N];
		}
		for (int i = 0; i < N; i++) {
			bool F = true;
			for (int j = 0; j < N; j++) {
				int s1 = j, s2 = (j + 1) % N;
				if (s1 == i || s2 == i) continue;
				if (intersect(S, A[i], A[s1], A[s2]) == true) F = false;
			}
			if (F == true) { dist[N][i] = dst(S, A[i]); dist[i][N] = dist[N][i]; }
		}
		for (int i = 0; i < N; i++) {
			bool F = true;
			for (int j = 0; j < N; j++) {
				int s1 = j, s2 = (j + 1) % N;
				if (s1 == i || s2 == i) continue;
				if (intersect(G, A[i], A[s1], A[s2]) == true) F = false;
			}
			if (F == true) { dist[N + 1][i] = dst(G, A[i]); dist[i][N + 1] = dist[N + 1][i]; }
		}

		// ベルマンフォード
		for (int k = 0; k < N + 2; k++) {
			for (int i = 0; i < N + 2; i++) {
				for (int j = 0; j < N + 2; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
		printf("%.12Lf\n", dist[N][N + 1]);
	}
	
	if (flag == false) {
		long double ans = 1e9;
		for (int i = 0; i < N; i++) ans = min(ans, dst(S, A[i]) + dst(A[i], G));
		for (int i = 0; i < N; i++) {
			int s1 = i, s2 = (i + 1) % N;
			long double L = 0, R = 1, c1, c2;
			for (int j = 0; j < 100; j++) {
				c1 = (L + L + R) / 3.0;
				c2 = (L + R + R) / 3.0;
				Point2 V1 = Point2{ A[s1].cx * (1.0L - c1) + A[s2].cx * c1, A[s1].cy * (1.0L - c1) + A[s2].cy * c1 };
				Point2 V2 = Point2{ A[s1].cx * (1.0L - c2) + A[s2].cx * c2, A[s1].cy * (1.0L - c2) + A[s2].cy * c2 };
				long double E1 = dst2(S, V1) + dst2(G, V1);
				long double E2 = dst2(S, V2) + dst2(G, V2);
				if (E1 > E2) { L = c1; }
				else { R = c2; }
				ans = min(ans, min(E1, E2));
			}
		}
		printf("%.12Lf\n", ans);
	}
	return 0;
}
