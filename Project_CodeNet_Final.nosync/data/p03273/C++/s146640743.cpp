#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, x, n) for (int i = x; i < n; i++)
#define REP2(i, x, n) for (int i = x; i <= n; i++)
#define OP(x) cout << x << endl;
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> void chmax(T& a, T b) { if(a > b) a = b; }
template<class T> void chmin(T& a, T b) { if(a < b) b = a; }
typedef long long ll;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w));
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }

    vector<vector<bool> > b(h, vector<bool>(w));

    rep(i, h){
        bool flag = true;
        rep(j, w){
            if(a[i][j] == '.'){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            rep(j, w){
                b[i][j] = true;
            }
        }
    }

    rep(i, w){
        bool flag = true;
        rep(j, h){
            if(a[j][i] == '.'){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            rep(j, h){
                b[j][i] = true;
            }
        }
    }

    rep(i, h){
        int cnt = 0;
        rep(j, w){
            if(b[i][j]){
                cnt++;
                continue;
            }
            cout << a[i][j];
        }
        if(cnt != w) cout << endl;
    }
}
