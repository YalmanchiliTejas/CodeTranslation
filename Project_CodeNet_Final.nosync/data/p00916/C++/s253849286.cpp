#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int h, w;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

bool isin(int i, int j){
    return i >= 0 && j >= 0 && i < h && j < w;
}

int main() {
    int n;
    while (cin >> n, n){
        VI l(n), t(n), r(n), b(n), x, y;
        REP(i,n){
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            l[i] *= 2;
            t[i] *= 2;
            r[i] *= 2;
            b[i] *= 2;
            FOR(j,-1,1){
                x.push_back(l[i]+j);
                x.push_back(r[i]+j);
                y.push_back(b[i]+j);
                y.push_back(t[i]+j);
            }
        }
        sort(ALL(x));
        sort(ALL(y));
        x.erase(unique(ALL(x)), x.end());
        y.erase(unique(ALL(y)), y.end());
        REP(i,n){
            l[i] = find(ALL(x), l[i]) - x.begin();
            r[i] = find(ALL(x), r[i]) - x.begin();
            b[i] = find(ALL(y), b[i]) - y.begin();
            t[i] = find(ALL(y), t[i]) - y.begin();
        }
        h = x.size(), w = y.size();

        VVI a(h, VI(w)), f(h, VI(w));
        REP(i,n){
            FOR(j,b[i],t[i]) a[l[i]][j] = a[r[i]][j] = 1;
            FOR(j,l[i],r[i]) a[j][b[i]] = a[j][t[i]] = 1;
        }

        int ans = 0;
        REP(i,h) REP(j,w){
            if (!a[i][j] && !f[i][j]){
                ans++;
                queue<P> que;
                que.push(P(i,j));
                while (!que.empty()){
                    P p = que.front();
                    que.pop();
                    int x = p.first, y = p.second;
                    if (f[x][y]) continue;
                    f[x][y] = 1;
                    REP(k,4){
                        int xx = x + dx[k], yy = y + dy[k];
                        if (!isin(xx,yy) || a[xx][yy] || f[xx][yy]) continue;
                        que.push(P(xx,yy));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}