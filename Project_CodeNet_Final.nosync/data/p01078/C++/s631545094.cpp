#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

class Point
{
public:
    double y, x;
    Point(){
        y = x = 0.0;
    }
    Point(double y0, double x0){
        y = y0;
        x = x0;
    }
    Point(double theta){
        y = sin(theta);
        x = cos(theta);
    }
    Point operator+(const Point& p) const{
        return Point(y + p.y, x + p.x);
    }
    Point operator-(const Point& p) const{
        return Point(y - p.y, x - p.x);
    }
    Point operator*(double a) const{
        return Point(y * a, x * a);
    }
    Point operator/(double a) const{
        return Point(y / a, x / a);
    }
    double length() const{
        return sqrt(y * y + x * x);
    }
    double dist(const Point& p) const{
        return sqrt(pow(y - p.y, 2) + pow(x - p.x, 2));
    }
    double dot(const Point& p) const{
        return y * p.y + x * p.x; // |a|*|b|*cos??
    }
    double cross(const Point& p) const{
        return x * p.y - y * p.x; // |a|*|b|*sin??
    }
    double angle() const{
        return atan2(y, x);
    }
};

Point segmentsIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2)
{
    double d = (a2 - a1).cross(b2 - b1);
    double r = (b1 - a1).cross(b2 - b1) / d;
    double s = (b1 - a1).cross(a2 - a1) / d;
    return a1 * (1.0 - r) + a2 * r;
}

double polygonArea(const vector<Point>& p)
{
    int n = p.size();
    double ret = 0.0;
    for(int i=0; i<n; ++i)
        ret += p[i].cross(p[(i+1)%n]);
    return abs(ret) / 2.0;
}

int main()
{
    int n, k;
    cin >> n >> k;

    Point o(0.0, 0.0);
    Point p0(0.0);
    Point p1(2.0 * M_PI / n);
    Point p2(2.0 * M_PI / n * k);
    Point p3(2.0 * M_PI / n * (1 - k));
    Point p4 = segmentsIntersection(p0, p2, p1, p3);

    vector<Point> v = {o, p0, p4, p1};
    double ans = polygonArea(v) * n;
    printf("%.10f\n", ans);

    return 0;
}