#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 100010;
const int MAX_V = 523;//0000;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const ull BS1 = 10000019ULL;
const int INF = (1 << 29);

inline int in() {int x; scanf("%d",&x); return x;}
inline ll lin() {ll x; scanf("%lld",&x); return x;}

inline void fastScan(int &x){
    bool negative = false;
    register int c = getchar();
    x = 0;
    for(   ; (c < 48 || c > 57) && (c != '-'); c = getchar());
    if(c == '-'){
        negative = true;
        c = getchar();
    }
    for(   ; (c > 47 && c < 58); c = getchar()){
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(negative)
        x = -x;
}

int fx[] = {1,-1,0,0};
int fy[] = {0,0,-1,1};

int n, m;
int par[N];

struct Edge {
    int u, v, cost;
    Edge(){}
    Edge(int _u, int _v, int _cost){
        u = _u; v = _v; cost = _cost;
    }
}eg[N * 5];

struct Point {
    int x, y, pos;
}point[N];

bool x_as(Point A, Point B){
    if(A.x == B.x){
        return A.y < B.y;
    }
    return A.x < B.x;
}

bool y_as(Point A, Point B){
    if(A.y == B.y){
        return A.x < B.x;
    }
    return A.y < B.y;
}

bool cost_as(Edge A, Edge B){
    return A.cost < B.cost;
}

int _find(int r){
    if(par[r] == r) return r;
    return par[r] = _find(par[r]);
}

int main(){
    fastScan(n);
    for(int i = 1; i <= n; i++){
        fastScan(point[i].x);
        fastScan(point[i].y);
        point[i].pos = i;
    }
    sort(point + 1, point + n + 1, x_as);
    for(int i = 2; i <= n; i++){
        eg[++m] = Edge(point[i - 1].pos, point[i].pos, abs(point[i - 1].x - point[i].x));
        eg[++m] = Edge(point[i - 1].pos, point[i].pos, abs(point[i - 1].y - point[i].y));
    }
    sort(point + 1, point + n + 1, y_as);
    for(int i = 2; i <= n; i++){
        eg[++m] = Edge(point[i - 1].pos, point[i].pos, abs(point[i - 1].x - point[i].x));
        eg[++m] = Edge(point[i - 1].pos, point[i].pos, abs(point[i - 1].y - point[i].y));
    }
    for(int i = 1; i < N; i++){
        par[i] = i;
    }
    sort(eg + 1, eg + m + 1, cost_as);
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        int U = _find(eg[i].u), V = _find(eg[i].v);
        if(U != V){
            ans += 1ll * eg[i].cost;
            par[U] = V;
        }
    }
    printf("%lld\n", ans);
}
