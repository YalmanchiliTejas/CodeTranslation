#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;
typedef long double ld;
const ld PI = acos(-1);

typedef complex<ld> P;

struct L {
    P a, b, v;
    L(){}
    L(P _a, P _b) : a(_a), b(_b), v(b - a) {}
};

P rot(P p, ld theta) {
    ld x = p.real(), y = p.imag();
    return P(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
}

ld cross(P a, P b) {
    return imag(conj(a) * b);
}

P crosspointSS(L l1, L l2) {
    ld d1 = abs(cross(l2.v, l1.a - l2.a)); // <----????
    // ld d1 = abs(cross(l2.v, l1.a - l2.b)); // <----????
    // ld d1 = abs(cross(l2.v, l1.b - l2.a)); // <----????
    ld d2 = abs(cross(l2.v, l1.b - l2.a));
    ld t = d1 / (d1 + d2);
    return l1.a + t * l1.v;
}

ld distanceLP(L l, P p) {
    return abs(cross(l.v, p - l.a)) / abs(l.v);
}

ld area(P p0, P p1, P p2) {
    p1 -= p0, p2 -= p0;
    return abs(cross(p1, p2)) / 2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ld N, K;
    cin >> N >> K;

    ld theta = 2 * PI / N;
    P p0(1, 0);
    P p1 = rot(p0, K * theta);
    P q0 = rot(p0, theta);
    P q1 = rot(q0, - K * theta);

    L l(p0, p1);
    L m(q0, q1);
    P C = crosspointSS(l, m);

    const P O(0, 0);
    ld ans = N * (area(O, p0, q0) - area(C, p0, q0));
    cout << setprecision(10) << ans << endl;
}