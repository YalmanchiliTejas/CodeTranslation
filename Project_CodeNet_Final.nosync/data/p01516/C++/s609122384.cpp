#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <functional>
#include <complex>
#include <stack>
#include <tuple>
#include <array>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)


typedef long long int ll;
typedef double D;      // ??§?¨?????????????double???long double?????????
typedef complex<D> P;  // Point
typedef vector<P> VP;


const int INF = (1<<30) - 1;
const D EPS = 1e-9;

#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

D dot(P a, P b) {
    return (conj(a)*b).X;
}
D cross(P a, P b) {
    return (conj(a)*b).Y;
}
int ccw(P a, P b, P c) {
    b -= a;	c -= a;
    //3???????????´???????????????
    if (cross(b,c) > EPS) return +1;	// counter clockwise
    if (cross(b,c) < -EPS) return -1;	// clockwise
    //3???????????´???????????????
    if (dot(b,c) < -EPS) return +2;		// c--a--b on line
    if (norm(b) < norm(c)) return -2;	// a--b--c on line or a==b
    return 0;							// a--c--b on line or a==c or b==c
}

bool isecSS(P a1, P a2, P b1, P b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
    ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

D distLP(P a1, P a2, P p) {
    //?°???±????????¨?????????????£?
    return abs(cross(a2-a1,p-a1))/abs(a2-a1);
}

D distSP(P a1, P a2, P p) {
    //?°???±????????¨?????????????£?
    if(LE(dot(a2-a1, p-a1), 0))
        return abs(p-a1);
    if(LE(dot(a1-a2, p-a2), 0))
        return abs(p-a2);
    return distLP(a1, a2, p);
}

D distSS(P a1, P a2, P b1, P b2) {
    if (isecSS(a1, a2, b1, b2)) return 0;
    return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
               min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}

class Star{
public:
    vector<P> points;
    
    Star(int x, int y, int a, int r){
        for(int i=0; i<5; i++){
            points.push_back(P(x, y) + P(0, r)*polar(1.0, 2*M_PI*i/5 + M_PI/180*a));
        }
    }
};

bool intersect(Star& star1, Star& star2){
    int order[] = {0, 2, 4, 1, 3};
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(isecSS(star1.points[order[i]], star1.points[order[(i+1)%5]], star2.points[order[j]], star2.points[order[(j+1)%5]]))
                return true;
        }
    }
    return false;
}

double distance(Star& star1, Star& star2){
    int order[] = {0, 2, 4, 1, 3};
    
    double ret = INF;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            ret = min(ret, distSS(star1.points[order[i]], star1.points[order[(i+1)%5]], star2.points[order[j]], star2.points[order[(j+1)%5]]));
        }
    }
    return ret;
}

class Edge{
public:
    int to;
    double cost;
    Edge(int to, double cost): to(to), cost(cost){};
};

double dijkstra(vector<vector<Edge> >& G, int s, int g){
    int N = G.size();
    vector<double> d(N, INF);
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    d[s] = 0;
    q.push(make_pair(d[s], s));
    
    while(!q.empty()){
        pair<double, int> v = q.top(); q.pop();
        if(v.first != d[v.second])
            continue;
        
        for(Edge &e: G[v.second]){
            if(e.cost + d[v.second] < d[e.to]){
                d[e.to] = e.cost + d[v.second];
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d[g];
}


int N, M, L;

//g++ -std=c++0x -msse4.2 -O3
//#include <bits/stdc++.h>
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(16);
    
    while(cin >> N >> M >> L, N|M|L){
        M--; L--;
        
        vector<Star> stars;
        for(int i=0; i<N; i++){
            int x, y, a, r; cin >> x >> y >> a >> r;
            stars.push_back(Star(x, y, a, r));
        }
        
        vector<vector<Edge>> G(N);
        
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                Star& star1 = stars[i];
                Star& star2 = stars[j];
                if(intersect(star1, star2)){
                    G[i].push_back(Edge(j, 0));
                    G[j].push_back(Edge(i, 0));
                }else{
                    double d = distance(star1, star2);
                    G[i].push_back(Edge(j, d));
                    G[j].push_back(Edge(i, d));
                }
            }
        }
        cout << dijkstra(G, M, L) << endl;
    }
    
    return 0;
}