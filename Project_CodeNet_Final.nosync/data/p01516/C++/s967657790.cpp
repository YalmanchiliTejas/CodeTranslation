#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

const double EPS = 1.0e-10;
const double PI = acos(-1.0);

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
        return y * p.y + x * p.x; // |a|*|b|*cos慮
    }
    double cross(const Point& p) const{
        return x * p.y - y * p.x; // |a|*|b|*sin慮
    }
};

double segmentPointDist(const Point& a1, const Point& a2, const Point& p)
{
    if((a2-a1).dot(p-a1) < 0)
        return a1.dist(p);
    else if((a1-a2).dot(p-a2) < 0)
        return a2.dist(p);
    else
        return abs((a2-a1).cross(p-a1)) / a1.dist(a2);
}

double segmentsDist(const Point& a1, const Point& a2, const Point& b1, const Point& b2)
{
    if(((a2-a1).cross(b1-a1) * (a2-a1).cross(b2-a1) < -EPS) && ((b2-b1).cross(a1-b1) * (b2-b1).cross(a2-b1) < -EPS))
        return 0.0;

    double ret = segmentPointDist(a1, a2, b1);
    ret = min(ret, segmentPointDist(a1, a2, b2));
    ret = min(ret, segmentPointDist(b1, b2, a1));
    ret = min(ret, segmentPointDist(b1, b2, a2));
    return ret;
}

void shortestPath(const vector<vector<double> >& graph, int start, vector<double>& dist)
{
    int n = graph.size();
    dist.assign(n, DBL_MAX);
    dist[start] = 0.0;
    priority_queue<pair<double,int> ,vector<pair<double,int> >, greater<pair<double,int> > > q;
    q.push(make_pair(0.0, start));

    while(!q.empty()){
        pair<double, int> p = q.top();
        q.pop();
        int v = p.second;
        if(dist[v] < p.first - EPS)
            continue;
        for(int i=0; i<n; ++i){
            if(dist[v] + graph[v][i] < dist[i] - EPS){
                dist[i] = dist[v] + graph[v][i];
                q.push(make_pair(dist[i], i));
            }
        }
    }
}

int main()
{
    for(;;){
        int n, m, l;
        cin >> n >> m >> l;
        if(n == 0)
            return 0;
        -- m;
        -- l;

        vector<vector<Point> > p(n, vector<Point>(5));
        for(int i=0; i<n; ++i){
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            for(int j=0; j<5; ++j)
                p[i][j] = Point(y, x) + Point((90 + a + 72 * j) / 180.0 * PI) * r;
        }

        vector<vector<double> > graph(n, vector<double>(n, DBL_MAX));
        for(int a=0; a<n; ++a){
            for(int b=a; b<n; ++b){
                for(int i=0; i<5; ++i){
                    for(int j=0; j<5; ++j){
                        graph[a][b] = min(graph[a][b], segmentsDist(p[a][i], p[a][(i+2)%5], p[b][j], p[b][(j+2)%5]));
                        graph[b][a] = min(graph[b][a], graph[a][b]);
                    }
                }
            }
        }

        vector<double> dist;
        shortestPath(graph, m, dist);
        printf("%.10f\n", dist[l]);
    }
}