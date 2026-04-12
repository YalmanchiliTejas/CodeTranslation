#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>>a(h, vector<char>(w));
    rep(i, h)rep(j, w)cin >> a[i][j];
    vector<int>row, line;
    bool ok = true;
    rep(i, h) {
        ok = true;
        rep(j, w) {
            if (a[i][j] == '#') {
                ok = false;
                break;
            }
        }
        if (ok)row.push_back(i);
    }
    rep(j, w) {
        ok = true;
        rep(i, h) {
            if (a[i][j] == '#') {
                ok = false;
                break;
            }
        }
        if (ok)line.push_back(j);
    }
    sort(row.begin(), row.end());
    sort(line.begin(), line.end());
    int ii = 0, ij = 0;
    rep(i, h) {
        if (ii < row.size() && i == row[ii]) {
            ii++;
            continue;
        }
        ij = 0;
        rep(j, w) {
            if (ij < line.size() && j == line[ij]) {
                ij++;
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}