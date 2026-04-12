#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define maxn 100005
struct edge{
    int x, y, c;
    edge(int _x, int _y, int _c):x(_x), y(_y), c(_c){}
};
int d[10][10], b[10][10];
int a[100][100];
int hit_i[100][100][10];
int hit_j[100][100][10];
int hit[100][100];
bool need[100][100];
void solve(){
    int n,m;
    cin >> n >> m;
    rep(i,n)rep(j,m){
        cin >> d[i][j];
    }
    rep(s,100)rep(t,100){
        rep(i,n)rep(j,m){
            a[s][t] = max(d[i][j] - (i + 1) * s - (j + 1) * t, a[s][t]);
        }
    }
    // rep(s, 100){
    //     rep(t, 100) cout << a[s][t] << ' ';
    //     cout << endl;
    // }
    rep(i,n)rep(j,m){
        b[i][j] = 1000000;
        rep(s,100)rep(t,100){
            b[i][j] = min(b[i][j], (i + 1) * s + (j + 1) * t + a[s][t]);
            if((i + 1) * s + (j + 1) * t + a[s][t] == d[i][j]){
                hit_i[s][t][i]  = 1;
                hit_j[s][t][j]  = 1;
                hit[s][t] += 1;
            }
        }
        if(b[i][j] > d[i][j]){
            cout << "Impossible" << endl;
            return;
        }
    }


    if (n == 1 && m == 1){
        need[0][0] = 1;
    }

    if (n == 1 && m > 1){
        rep(s, 100)rep(t, 100){
            if (hit[s][t] < 2) continue;
            if (s > 0) continue;
            need[s][t] = 1;
        }
    }

    if (n > 1 && m == 1){
        rep(s, 100)rep(t, 100){
            if (hit[s][t] < 2) continue;
            if (t > 0) continue;
            need[s][t] = 1;
        }
    }

    if (n > 1 && m > 1){
        rep(s, 100)rep(t, 100){
            if (hit[s][t] < 3) continue;
            int cnt = 0;
            rep(i, n) cnt += hit_i[s][t][i];
            if (cnt < 2) continue;
            cnt = 0;
            rep(j, m) cnt += hit_j[s][t][j];
            if (cnt < 2) continue;
            need[s][t] = 1;
        }        
    }

    int S, T, node;
    S = 1;
    T = 2;
    node = 3;
    vector<edge> e; e.clear();
    rep(s,100)rep(t,100) if(need[s][t]){
        // s X + t Y + a[s][t]
        vector<int> v;
        v.clear();
        rep(_, s) v.push_back(-2);
        rep(_, t) v.push_back(-1);
        rep(_, a[s][t] / 100) v.push_back(100);
        if(a[s][t] % 100 > 0) v.push_back(a[s][t] % 100);
        int last = S;
        rep(i, v.size()){
            if (i == v.size() - 1) e.push_back(edge(last, T, v[i]));
            else{
                e.push_back(edge(last, node, v[i]));
                last = node;
                node ++;
            }
        }
    }
    cout << "Possible" << endl;
    cout << node - 1 << ' ' << e.size() << endl;
    for(auto p: e){
        cout << p.x << ' ' << p.y << ' ';
        if(p.c == -2) cout << 'X'; else
        if(p.c == -1) cout << 'Y'; else
        cout << p.c;
        cout << endl;
    }
    cout << "1 2" <<endl;
}

int main(int argc, char const *argv[]) {
    solve();
    return 0;
}
