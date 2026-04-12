#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, INDEX = 1;

struct Point {
    int id, x, y;

    Point() {
        this->id = 0;
        this->x = 0;
        this->y = 0;
    }

    Point(int id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
};

struct Edge {
    int id;

    Point p1, p2;

    Edge() {
        this->id = id;
        this->p1 = Point();
        this->p2 = Point();
    }

    Edge(int id, Point p1, Point p2) {
        this->id = id;
        this->p1 = p1;
        this->p2 = p2;
    }

    int getLength() {
        return min(abs(p1.x - p2.x), abs(p1.y - p2.y));
    }

    friend bool operator < (Edge e1, Edge e2) {
        if (e1.getLength() < e2.getLength()) {
            return true;
        }

        if (e1.getLength() > e2.getLength()) {
            return false;
        }

        return e1.id < e2.id;
    }
};

int n, dsu[MAX_N + INDEX], h[MAX_N + INDEX];

Point points[MAX_N + INDEX];

vector<Edge> edges;

bool compX(Point p1, Point p2) {
    if (p1.x < p2.x) {
        return true;
    }

    if (p1.x > p2.x) {
        return false;
    }

    return p1.id < p2.id;
}

bool compY(Point p1, Point p2) {
    if (p1.y < p2.y) {
        return true;
    }

    if (p1.y > p2.y) {
        return false;
    }

    return p1.id < p2.id;
}

bool compId(Point p1, Point p2) {
    return p1.id < p2.id;
}

int get(int i) {
    if (dsu[i] != i) {
        dsu[i] = get(dsu[i]);
    }

    return dsu[i];
}

void join(int a, int b) {
    a = get(a);
    b = get(b);

    if (a == b) {
        return ;
    }

    if (h[a] > h[b]) {
        dsu[b] = a;

        h[a] = max(h[a], h[b] + 1);
    } else {
        dsu[a] = b;

        h[b] = max(h[b], h[a] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;

        cin >> x >> y;

        points[i] = Point(i, x, y);
    }

    sort(points + INDEX, points + INDEX + n, compX);

    for (int i = 1; i < n; i++) {
        edges.push_back(Edge(i, points[i], points[i + 1]));
    }

    sort(points + INDEX, points + INDEX + n, compY);

    for (int i = 1; i < n; i++) {
        edges.push_back(Edge(n + i - 1, points[i], points[i + 1]));
    }

    sort(edges.begin(), edges.end(), less<Edge>());

    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        h[i] = 1;
    }

    int ans = 0;
    for (Edge e: edges) {
        if (get(e.p1.id) == get(e.p2.id)) {
            continue;
        }

        join(e.p1.id, e.p2.id);

        ans += e.getLength();
    }

    cout << ans << endl;

    return 0;
}
