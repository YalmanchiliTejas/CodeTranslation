#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 210;
int d[N][N];

struct Edge {
    int u, v;
    string c;
};  

int f[N][N];

int g[N][N];

//change to 100!
const int LEN = 100;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int A, B;
    cin >> A >> B;
    for (int i = 1; i <= A; ++i)
        for (int j = 1; j <= B; ++j)
            cin >> d[i][j];    

    int S = 1;
    int T = 2;
    int ptr = 3;
    vector <Edge> ans;

    int lx = ptr;
    ans.app({S, ptr, "X"});
    ++ptr;
    for (int i = 1; i <= LEN; ++i) {
        ans.app({ptr - 1, ptr, "X"});
        ++ptr;
    }   
    ans.app({ptr - 1, T, "X"});
    int rx = ptr - 1;

    
    int ly = ptr;
    ans.app({S, ptr, "Y"});
    ++ptr;
    for (int i = 1; i <= LEN; ++i) {
        ans.app({ptr - 1, ptr, "Y"});
        ++ptr;
    }   
    ans.app({ptr - 1, T, "Y"});
    int ry = ptr - 1;
    
    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) {
            for (int x = 0; x <= 100; ++x) {
                for (int y = 0; y <= 100; ++y) {

                    int have = x * i + y * j;
                    if (have < d[i][j]) {
                        f[x][y] = max(f[x][y], d[i][j] - have);
                    }   
                
                }   
            }   
        }   
    }   

    for (int x = 0; x <= LEN/2; ++x) {
        for (int y = 0; y <= LEN/2; ++y) {

            int u = lx + x - 1;
            if (x == 0)
                u = S;

            int v = ry - y + 1;
            if (y == 0)
                v = T;

            if (f[x][y] > 100)
                continue;

            ans.app({u, v, to_string(f[x][y])});
        }   
    }   

    for (int x = 1; x <= A; ++x) {
        for (int y = 1; y <= B; ++y) {
            const int INF = 1e9+7;
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    g[i][j] = INF;
            for (auto e : ans) {
                if (e.c == "X") {
                    g[e.u][e.v] = min(g[e.u][e.v], x);
                }   
                else if (e.c == "Y") {
                    g[e.u][e.v] = min(g[e.u][e.v], y);
                }
                else {
                    g[e.u][e.v] = min(g[e.u][e.v], stoi(e.c));
                }   
            }
            
            for (int k = 0; k < N; ++k)
                for (int u = 0; u < N; ++u)
                    for (int v = 0; v < N; ++v)
                        g[u][v] = min(g[u][v], g[u][k]+g[k][v]);       

            if (g[S][T] != d[x][y]) {
                cout << "Impossible" << endl;
                exit(0);
            }   
        }
    }    
    
    for (auto e : ans) {
        if (e.u == e.v) {
            cout << "LMAO" << endl;
            exit(1);                        
        }   
    }   
    for (int i = 0; i < ans.size(); ++i)
        for (int j = i + 1; j < ans.size(); ++j) {
            if (ans[i].u == ans[j].u && ans[i].v == ans[j].v) {
                cout << "LMAO" << endl;
                exit(1);
            }   
        }   

    cout << "Possible" << endl;
    cout << 300 << ' ' << ans.size() << endl;
    for (auto e : ans)
        cout << e.u << ' ' << e.v << ' ' << e.c << endl;
    cout << S << ' ' << T << endl;
}