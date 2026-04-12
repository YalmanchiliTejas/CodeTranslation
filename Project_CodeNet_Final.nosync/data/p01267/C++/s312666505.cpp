#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define FOR(i, b, e) for(int i = b; i < e; i++)
#define to_bit(i) static_cast< bitset<8> >(i)
#define INF (1<<28)
#define int(n) int n; cin >> n;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long>PLL;
typedef queue<int> QI;
typedef priority_queue<int> maxpq;
typedef priority_queue<int, vector<int>, greater<int> > minpq;

struct edge{int to, cost;};
int gcd(int a, int b){if(a%b==0){return(b);}else{return(gcd(b,a%b));}};
int lcm(int m, int n){if((0 == m)||(0 == n)){return 0;} return ((m / gcd(m, n)) * n);};
unsigned long long comb(long n, long m){if(n < m) return 0;
    unsigned long long c = 1; m = (n - m < m ? n - m : m);
    for(long ns = n - m + 1, ms = 1; ms <= m; ns ++, ms ++){c *= ns; c /= ms;} return c;};
int quadratic(int a, int b, int c){return (int)(-b + sqrt(b*b - 4*a*c)) / 2*a;}

void cp(int a1[], int a2[], int l){REP(i, l) a2[i] = a1[i];};
void cp(string a1[], string a2[], int l){REP(i, l) a2[i] = a1[i];};
double sq(double d){return d*d;};
int sq(int i){return i*i;};
double sqdist(int x1, int y1, int x2, int y2){
    double dx = x1 - x2, dy = y1 - y2; return dx*dx + dy*dy;
};
bool inside(int y, int x, int h, int w){return 0 <= y && y <= (h-1) && 0 <= x && x <= (w-1);};


// 線分の交差判定
bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    // 並行な場合
    int m = (x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
    if(m == 0) return false;
    // 媒介変数の値が0より大きく1以下なら交差する、これは問題の状況によって変わるかも。
    double r =(double)((y4-y3)*(x3-x1)-(x4-x3)*(y3-y1))/m;
    double s =(double)((y2-y1)*(x3-x1)-(x2-x1)*(y3-y1))/m;
    return (0 < r && r <= 1 && 0 < s && s <= 1);
};

// 外積の計算 AB CD の内積を求める
int crossProdct(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy){
    int abx = bx - ax; int aby = by - ay;
    int cdx = dx - cx; int cdy = dy - cy;
    return abx * cdy - cdx * aby;
};
double crossProdct(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
    double abx = bx - ax; double aby = by - ay;
    double cdx = dx - cx; double cdy = dy - cy;
    return abx * cdy - cdx * aby;
};
double innerProduct(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
    double abx = bx - ax; double aby = by - ay;
    double cdx = dx - cx; double cdy = dy - cy;
    return abx * cdx + aby * cdy;
};

// 三角形の内部判定 ABCの中にPがあるか判定
bool inTriangle(int ax, int ay, int bx, int by, int cx, int cy, int px, int py){
    int c1 = crossProdct(ax, ay, bx, by, bx, by, px, py);
    int c2 = crossProdct(bx, by, cx, cy, cx, cy, px, py);
    int c3 = crossProdct(cx, cy, ax, ay, ax, ay, px, py);
    return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0);
};
bool inTriangle(double ax, double ay, double bx, double by, double cx, double cy, double px, double py){
    double c1 = crossProdct(ax, ay, bx, by, bx, by, px, py);
    double c2 = crossProdct(bx, by, cx, cy, cx, cy, px, py);
    double c3 = crossProdct(cx, cy, ax, ay, ax, ay, px, py);
    return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0);
};

// 三角形の外心
void circumcenter(double x1, double y1, double x2, double y2, double x3, double y3, double res[3]){
    double xp1 = (y1-y3)*(y1*y1-y2*y2+x1*x1-x2*x2) - (y1-y2)*(y1*y1-y3*y3+x1*x1-x3*x3);
    double xp2 = 2*(y1-y3)*(x1-x2)-2*(y1-y2)*(x1-x3);
    res[0] = xp1/xp2;
    double yp1 = (x1-x3)*(x1*x1-x2*x2+y1*y1-y2*y2) - (x1-x2)*(x1*x1-x3*x3+y1*y1-y3*y3);
    double yp2 = 2*(x1-x3)*(y1-y2)-2*(x1-x2)*(y1-y3);
    res[1] = yp1/yp2;
    double r = (x3-res[0])*(x3-res[0])+(y3-res[1])*(y3-res[1]);
    res[2] = sqrt(r);
}



class BinaryIndexedTree{
public:
    int n; vector<int> bit;
    BinaryIndexedTree(int _n){
        n = _n;
        bit.resize(n+1,0);
    }
    int sum(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    void add(int i, int v){
        while(i <= n){
            bit[i] += v;
            i += i & -i;
        }
    }
};


class UnionFindTree{
public:
    vector<int> parent, rank;
    int n;
    int cnt;
    // 初期化
    UnionFindTree(int _n){
        n = _n;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        cnt = n;
    }
    // 根を求める
    int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            return parent[x] = find(parent[x]);
        }
    }
    // xとyの集合を結合
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            // set.insert(x);
            return;
        }
        if(rank[x] < rank[y]){
            parent[x] = y;
            cnt--;
        }else{
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
            cnt--;
        }
    }
    // xとyが同じ集合か
    bool same(int x, int y){
        return find(x) == find(y);
    }
};



// ワーシャルフロイド法
void warshallFloyd(int graph[100][100], int graph_size){
    for(int mid_node = 0; mid_node < graph_size; mid_node++)
        for(int s_node = 0; s_node < graph_size; s_node++)
            for(int g_node = 0; g_node < graph_size; g_node++)
                if(s_node == g_node) graph[s_node][g_node] = 0;
                else graph[s_node][g_node] = min(graph[s_node][g_node], graph[s_node][mid_node] + graph[mid_node][g_node]);
};


// d:隣接行列  n:グラフのサイズ  s:始点  dist:始点からの距離が入る配列
void dijkstra(int graph[1000][1000], int node_count, int start_node, int distances[1000]){
    // 距離を-1で初期化
    REP(i, node_count) distances[i] = -1;
    distances[start_node] = 0;
    // pair<int,int> で最初のintでソートされるプライオリティキュー
    priority_queue<PII, vector<PII>, greater<PII> > dijkstra_pq;
    dijkstra_pq.push(PII(0, start_node));
    while (!dijkstra_pq.empty()) {
        PII p = dijkstra_pq.top(); dijkstra_pq.pop();
        int i = p.second;
        // popしたノードの最短距離が、既にわかっているものより小さかったらそのまま捨てる
        if(distances[i] < p.first) continue;
        // ノードを見る
        for(int j = 0; j < node_count; j++){
            if(graph[i][j] == -1) continue;
            if(distances[j] == -1){
                distances[j] = distances[i] + graph[i][j];
                dijkstra_pq.push(PII(distances[j], j));
            }else if(distances[j] > distances[i] + graph[i][j]){
                distances[j] = distances[i] + graph[i][j];
                dijkstra_pq.push(PII(distances[j], j));
            }
        }
    }
};




/**
 * start
 * @author yoshikyoto
 */

int n, gnum, e;
int g[105][105];

int mfdfs(int curr, int goal, int min_flow, int used[105], int g[105][105], int n){
    cout << "dfs" << endl;
    if(curr == goal) return min_flow;
    REP(next, n){
        if(g[curr][next] && !used[next]){
            used[next] = 1;
            int flow = mfdfs(next, goal, min(min_flow, g[curr][next]), used, g, n);
            if(flow){
                g[curr][next] -= flow;
                g[next][curr] += flow;
                return flow;
            }
        }
    }
    return 0;
}

int max_flow(int g[105][105], int n, int s, int t){
    int flow = 0;
    while(true){
        int used[105];
        REP(i, n) used[i] = 0;
        used[s] = 1;
        int tmp_flow = mfdfs(s, t, INF, used, g, n);
        if(tmp_flow == 0) return flow;
        flow += tmp_flow;
    }
}


int main(int argc, const char * argv[]){
    while (true) {
        int n, a, b, c, x, y[100];
        cin >> n >> a >> b >> c >> x;
        if(!(n|a|b|c|x)) break;
        REP(i, n) cin >> y[i];
        
        int cnt = 0, p = 0;
        while(true){
            if(y[p] == x) p++;
            if(cnt > 10000){
                cout << -1 << endl;
                break;
            }else if(p == n){
                cout << cnt << endl;
                break;
            }
            cnt++;
            x = (a * x + b) % c;
        }
    }
}