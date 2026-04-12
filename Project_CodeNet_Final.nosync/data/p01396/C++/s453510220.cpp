#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;

#define DE 1
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(s) (s).begin(),(s).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define EACH(i,s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(__typeof__(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}



const int MAX = 1010;

struct Graph {
    static const int MAX_V_ = ::MAX;
    int L;
    vector<int> list[MAX_V_];
    
    void init(int n = 0) {L = n; for (int i = 0; i < MAX_V_; ++i) list[i].clear();}
    inline vector<int>& operator [] (int i) {return list[i];}
    friend ostream& operator << (ostream& s, const Graph& G) {for (int i = 0; i < G.L; ++i) {s << i << " : " << G.list[i];}return s;}
    
    void addedge(int from, int to) {
        list[from].push_back(to);
    }
} G;

int L = 0;
bool seen[MAX];
bool matched[MAX];
int level[MAX];
int matching[MAX];

void hobfs(Graph &G) {
    queue<int> que;
    for (int left = 0; left < L; ++left) {
        level[left] = -1;
        if (!matched[left]) {
            que.push(left);
            level[left] = 0;
        }
    }
    level[L] = L;
    while (!que.empty()) {
        int left = que.front();
        que.pop();
        for (int i = 0; i < G[left].size(); ++i) {
            int right = G[left][i];
            int next = matching[right];
            if (level[next] == -1) {
                level[next] = level[left] + 1;
                que.push(next);
            }
        }
    }
}

bool hodfs(Graph &G, int left) {
    if (left == L) return true;
    if (seen[left]) return false;
    seen[left] = true;
    for (int i = 0; i < G[left].size(); ++i) {
        int right = G[left][i];
        int next = matching[right];
        if (level[next] > level[left] && hodfs(G, next)) {
            matching[right] = left;
            return true;
        }
    }
    return false;
}

int Hopcroft_Karp(Graph &G) {
    L = G.L;
    for (int i = 0; i < MAX; ++i) matching[i] = L;
    memset(matched, 0, sizeof(matched));
    
    int res = 0;
    while (true) {
        hobfs(G);
        memset(seen, 0, sizeof(seen));
        bool finished = true;
        for (int left = 0; left < L; ++left) {
            if (!matched[left] && hodfs(G, left)) {
                matched[left] = true;
                ++res;
                finished = false;
            }
        }
        if (finished) break;
    }
    return res;
}


int H, W;
vint h[MAX];
int temp[MAX][MAX];
bool connected[MAX][MAX];

bool solve() {
    bool res = true;
    
    int pMax = -1, Max = -1;
    for (int i = 0; i < H; ++i) if (Max < h[i][0]) {Max = h[i][0], pMax = i;}
    for (int i = 0; i < W; ++i) {
        int epMax = -1, eMax = -1;
        for (int j = 0; j < H; ++j) if (eMax < h[j][i]) {eMax = h[j][i], epMax = j;}
        if (epMax != pMax) {res = false; break;}
    }
    if (res) {
        sort(h, h + H);
        for (int i = 0; i < H; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (!connected[i][j]) {
                    bool ok = true;
                    for (int k = 0; k < W; ++k) if (h[i][k] <= h[j][k]) {ok = false; break;}
                    if (ok) {
                        connected[i][j] = true;
                        for (int k = 0; k < H; ++k) connected[i][k] |= connected[j][k];
                    }
                }
            }
        }
        G.init(H);
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < H; ++j) {
                if (i == j) continue;
                if (connected[i][j]) G.addedge(i,j);
            }
        
        int ans = Hopcroft_Karp(G);
        if (H - ans > 2) res = false;
    }

    return res;
}

int main() {  
    cin >> H >> W;
    for (int i = 0; i < H; ++i) h[i].resize(W, 0);
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
        scanf("%d", &h[i][j]);
        temp[j][i] = h[i][j];
    }
    
    bool can = true;
    if (!solve()) can = false;
        
    if (can) {
        for (int i = 0; i < W; ++i) 
            for (int j = 0; j < H; ++j) 
                temp[i][j] = h[j][i];
        for (int i = 0; i < W; ++i) h[i].resize(H, 0);
        for (int i = 0; i < W; ++i) 
            for (int j = 0; j < H; ++j)
                h[i][j] = temp[i][j];
        swap(H, W);
       
        if (!solve()) can = false;
    }
        
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
