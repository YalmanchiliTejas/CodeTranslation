#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

vector<char> data = {'W','S'};

int n;
string s;

bool dfs(char x, char y, int v, vector<char> &d) {
    if (v == 0) {
        d[v] = x;
        if (dfs(x,y,v+1,d)) return true;
    }
    else if (v == n-1) {
        d[v] = y;
        bool ok = true;
        if (s[n-1] == 'o' && s[0] == 'o') {
            if (d[n-1] == 'S') {
                if (d[n-2] != d[0]) ok = false;
            }
            if (d[n-1] == 'W') {
                if (d[n-2] == d[0]) ok = false;
            }
            if (d[0] == 'S') {
                if (d[n-1] != d[1]) ok = false;
            }
            if (d[0] == 'W') {
                if (d[n-1] == d[1]) ok = false;
            }
        }
        if (s[n-1] == 'o' && s[0] == 'x') {
            if (d[n-1] == 'S') {
                if (d[n-2] != d[0]) ok = false;
            }
            if (d[n-1] == 'W') {
                if (d[n-2] == d[0]) ok = false;
            }
            if (d[0] == 'S') {
                if (d[n-1] == d[1]) ok = false;
            }
            if (d[0] == 'W') {
                if (d[n-1] != d[1]) ok = false;
            }
        }
        if (s[n-1] == 'x' && s[0] == 'o') {
            if (d[n-1] == 'S') {
                if (d[n-2] == d[0]) ok = false;
            }
            if (d[n-1] == 'W') {
                if (d[n-2] != d[0]) ok = false;
            }
            if (d[0] == 'S') {
                if (d[n-1] != d[1]) ok = false;
            }
            if (d[0] == 'W') {
                if (d[n-1] == d[1]) ok = false;
            }
        }
        if (s[n-1] == 'x' && s[0] == 'x') {
            if (d[n-1] == 'S') {
                if (d[n-2] == d[0]) ok = false;
            }
            if (d[n-1] == 'W') {
                if (d[n-2] != d[0]) ok = false;
            }
            if (d[0] == 'S') {
                if (d[n-1] == d[1]) ok = false;
            }
            if (d[0] == 'W') {
                if (d[n-1] != d[1]) ok = false;
            }
        }
        return ok;
    }
    else {
        d[v] = y;
        char n_x = y;
        char n_y;
        if (s[v] == 'o') {
            if (y == 'S') n_y = x;
            if (y == 'W') {
                if (x == 'W') n_y = 'S';
                if (x == 'S') n_y = 'W';
            }
        }
        if (s[v] == 'x') {
            if (y == 'W') n_y = x;
            if (y == 'S') {
                if (x == 'W') n_y = 'S';
                if (x == 'S') n_y = 'W';
            }
        }
        if (dfs(n_x,n_y,v+1,d)) return true;
    }
    return 0;
}

int main() {
    cin >> n >> s;
    vector<char> d(n);
    rep(i,2)rep(j,2) {
        if (dfs(data[i],data[j],0,d)) {
            rep(i,n) cout << d[i];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}   